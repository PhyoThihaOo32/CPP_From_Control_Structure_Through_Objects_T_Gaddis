(function () {
  const progressStorageKey = "cpp-study-guide-progress-v2";
  const previewCache = new Map();

  const state = {
    query: "",
    viewType: "overview",
    viewId: "overview",
    activeExamplePath: null,
    activeProgramPath: null,
  };

  const heroStatsEl = document.getElementById("heroStats");
  const globalProgressEl = document.getElementById("globalProgress");
  const searchSummaryEl = document.getElementById("searchSummary");
  const searchInputEl = document.getElementById("searchInput");
  const navPrimaryEl = document.getElementById("navPrimary");
  const navChaptersEl = document.getElementById("navChapters");
  const navSupplementalEl = document.getElementById("navSupplemental");
  const mainContentEl = document.getElementById("mainContent");

  function readProgress() {
    try {
      return JSON.parse(localStorage.getItem(progressStorageKey) || "{}");
    } catch (error) {
      return {};
    }
  }

  function writeProgress(progress) {
    localStorage.setItem(progressStorageKey, JSON.stringify(progress));
  }

  function getExerciseProgress(exerciseId) {
    return Boolean(readProgress()[exerciseId]);
  }

  function setExerciseProgress(exerciseId, done) {
    const progress = readProgress();
    progress[exerciseId] = done;
    writeProgress(progress);
  }

  function completionForExercises(exercises) {
    if (!exercises || exercises.length === 0) {
      return { done: 0, total: 0, percent: 0 };
    }

    const done = exercises.filter((exercise) => getExerciseProgress(exercise.id)).length;
    return {
      done,
      total: exercises.length,
      percent: Math.round((done / exercises.length) * 100),
    };
  }

  function getAllExercises() {
    return COURSE_DATA.chapters.flatMap((chapter) => chapter.exercises);
  }

  function getGlobalCompletion() {
    return completionForExercises(getAllExercises());
  }

  function escapeHtml(value) {
    return String(value)
      .replaceAll("&", "&amp;")
      .replaceAll("<", "&lt;")
      .replaceAll(">", "&gt;")
      .replaceAll('"', "&quot;")
      .replaceAll("'", "&#39;");
  }

  function matchesQuery(section, query) {
    if (!query) {
      return true;
    }

    const haystack = [
      section.label,
      section.title,
      section.folder,
      section.summary,
      section.whyItMatters,
      section.recommendation,
      ...(section.topics || []).flatMap((topic) => [topic.title, topic.description]),
      ...(section.deepDive?.focusAreas || []).flatMap((item) => [item.title, item.description]),
      ...(section.deepDive?.commonMistakes || []),
      ...(section.deepDive?.miniProjects || []),
      ...(section.bestFor || []),
      ...(section.breakdown || []),
      ...(section.exampleFiles || []).flatMap((file) => [
        file.name,
        file.note,
        file.whatItDoes,
        file.whyThisProgramMatters,
        ...(file.concepts || []),
        ...(file.studyNotes || []),
        ...(file.watchFor || []),
        ...(file.sampleRun || []),
        ...(file.codeSamples || []).flatMap((sample) => [
          sample.title,
          sample.note,
          ...(Array.isArray(sample.snippet) ? sample.snippet : [sample.snippet]),
        ]),
        ...(file.practice || []).map((item) => item.task),
      ]),
      ...(section.exercises || []).flatMap((exercise) => [exercise.title, exercise.prompt, exercise.hint]),
    ]
      .filter(Boolean)
      .join(" ")
      .toLowerCase();

    return haystack.includes(query.toLowerCase());
  }

  function getFilteredChapters() {
    return COURSE_DATA.chapters.filter((chapter) => matchesQuery(chapter, state.query));
  }

  function getFilteredSupplemental() {
    return COURSE_DATA.supplemental.filter((item) => matchesQuery(item, state.query));
  }

  function getEntity(viewType, viewId) {
    if (viewType === "chapter") {
      return COURSE_DATA.chapters.find((chapter) => chapter.id === viewId) || null;
    }

    if (viewType === "supplemental") {
      return COURSE_DATA.supplemental.find((item) => item.id === viewId) || null;
    }

    return null;
  }

  function setView(viewType, viewId) {
    state.viewType = viewType;
    state.viewId = viewId;
    state.activeProgramPath = null;

    if (viewType === "overview") {
      state.activeExamplePath = null;
      render();
      return;
    }

    const entity = getEntity(viewType, viewId);
    state.activeExamplePath = entity && entity.exampleFiles.length > 0 ? entity.exampleFiles[0].path : null;

    if (entity && viewType === "chapter" && hasProgramWalkthrough(entity)) {
      const firstProgram = getDetailedProgramFiles(entity)[0] || null;
      if (firstProgram) {
        state.activeProgramPath = firstProgram.path;
        state.activeExamplePath = firstProgram.path;
      }
    }

    render();
  }

  function estimateStudyTime(entity) {
    const baseMinutes =
      (entity.topics?.length || 0) * 14 +
      (entity.exampleFiles?.length || 0) * 10 +
      (entity.exercises?.length || 0) * 15;

    const low = Math.max(25, Math.round(baseMinutes * 0.75 / 5) * 5);
    const high = Math.max(low + 10, Math.round(baseMinutes * 1.15 / 5) * 5);
    return `${low}-${high} min`;
  }

  function difficultyBreakdown(exercises) {
    const counts = { Easy: 0, Medium: 0, Hard: 0 };
    exercises.forEach((exercise) => {
      counts[exercise.difficulty] = (counts[exercise.difficulty] || 0) + 1;
    });
    return counts;
  }

  function buildLearningOutcomes(entity) {
    const verbs = ["Understand", "Practice", "Apply", "Explain"];
    return entity.topics.map((topic, index) => `${verbs[index % verbs.length]} ${topic.title.toLowerCase()} with working C++ examples.`);
  }

  function buildStudySequence(entity) {
    const firstFile = entity.exampleFiles[0]?.name || "the first example file";
    const secondFile = entity.exampleFiles[1]?.name || "a second example file";
    return [
      `Start with the chapter summary and the "Why it matters" note so the topic has a purpose before the syntax.`,
      `Read ${firstFile} first, then compare it with ${secondFile} to see how the idea grows in complexity.`,
      `Trace one example in the source preview and write down what each important variable, branch, or loop is doing.`,
      `Complete the practice ladder from easiest to hardest, then move to Programming Challenges if you want a tougher follow-up.`,
    ];
  }

  function buildReviewChecklist(entity) {
    const firstExample = entity.exampleFiles[0]?.name || "one example file";
    return [
      `I can explain the core idea of ${entity.title.toLowerCase()} without reading directly from the code.`,
      `I can trace ${firstExample} line by line and predict its output before running it.`,
      `I can modify one example from this folder to handle a new test case or slightly different requirement.`,
      `I completed at least one guided exercise and can describe what changed from the original example.`,
    ];
  }

  function hasProgramWalkthrough(entity) {
    return getDetailedProgramFiles(entity).length > 0;
  }

  function getDetailedProgramFiles(entity) {
    return entity.exampleFiles.filter((file) => file.whatItDoes || (file.practice && file.practice.length > 0));
  }

  function programUsesInput(file) {
    const concepts = file.concepts || [];
    const text = [file.whatItDoes, ...(file.studyNotes || [])].join(" ").toLowerCase();
    return (
      concepts.some((concept) =>
        ["input", "getline", "cin", "mixed input", "keyboard"].some((needle) => concept.toLowerCase().includes(needle))
      ) ||
      text.includes("asks the user") ||
      text.includes("reads ")
    );
  }

  function buildProgramSteps(file) {
    if (file.buildSteps && file.buildSteps.length > 0) {
      return file.buildSteps;
    }

    const steps = [];

    if ((file.concepts || []).some((concept) => concept.toLowerCase().includes("const"))) {
      steps.push("Declare the named constants first, then declare the regular variables the program will use.");
    } else {
      steps.push("Declare the variables the program needs so the input, calculation, and output parts are clear.");
    }

    if (programUsesInput(file)) {
      steps.push("Write the prompts and read the values in the same order the user will naturally answer them.");
    } else {
      steps.push("Initialize the example values directly in the program so the core idea is easy to see.");
    }

    if ((file.concepts || []).some((concept) => concept.toLowerCase().includes("random"))) {
      steps.push("Set up the random generator and map the value into the range the program needs.");
    } else if ((file.concepts || []).some((concept) => concept.toLowerCase().includes("math"))) {
      steps.push("Write the main formula or math-library expression that turns the input into the result.");
    } else if ((file.concepts || []).some((concept) => concept.toLowerCase().includes("format"))) {
      steps.push("Apply the formatting settings before printing the final report or message.");
    } else {
      steps.push("Write the main calculation or core logic step that produces the result from the stored data.");
    }

    steps.push("Print the result with labels the user can understand without reading the code.");
    return steps;
  }

  function getChapterIndex(entityId) {
    return COURSE_DATA.chapters.findIndex((chapter) => chapter.id === entityId);
  }

  function getAdjacentChapters(entityId) {
    const index = getChapterIndex(entityId);
    return {
      previous: index > 0 ? COURSE_DATA.chapters[index - 1] : null,
      next: index >= 0 && index < COURSE_DATA.chapters.length - 1 ? COURSE_DATA.chapters[index + 1] : null,
    };
  }

  function renderHeroStats() {
    const stats = [
      { value: COURSE_DATA.summary.moduleCount, label: "Study modules" },
      { value: COURSE_DATA.summary.chapterSources, label: "Primary chapter files" },
      { value: COURSE_DATA.summary.challengeSources, label: "Challenge-bank files" },
      { value: COURSE_DATA.summary.professorSources, label: "Supplemental source files" },
    ];

    heroStatsEl.innerHTML = stats
      .map(
        (stat) => `
          <div class="stat-card">
            <span class="stat-value">${escapeHtml(stat.value)}</span>
            <span class="stat-label">${escapeHtml(stat.label)}</span>
          </div>
        `
      )
      .join("");
  }

  function renderGlobalProgress() {
    const completion = getGlobalCompletion();
    globalProgressEl.innerHTML = `
      <h3>Overall progress</h3>
      <div class="progress-meter" aria-hidden="true">
        <div class="progress-fill" style="width: ${completion.percent}%;"></div>
      </div>
      <div class="progress-copy">
        <span>${escapeHtml(`${completion.done} of ${completion.total} guided exercises complete`)}</span>
        <strong>${escapeHtml(`${completion.percent}%`)}</strong>
      </div>
    `;
  }

  function renderSearchSummary() {
    const filteredChapters = getFilteredChapters();
    const filteredSupplemental = getFilteredSupplemental();
    const hasQuery = Boolean(state.query);

    searchSummaryEl.innerHTML = `
      <strong>${hasQuery ? "Filtered results" : "Browse the full study map"}</strong>
      <div class="muted-copy">
        ${
          hasQuery
            ? `Showing ${filteredChapters.length} chapter modules and ${filteredSupplemental.length} supplemental guides for <span class="inline-code">${escapeHtml(state.query)}</span>.`
            : "Use the search box to jump to a chapter, topic, folder, or source filename."
        }
      </div>
    `;
  }

  function renderNavButtons(container, items, viewType) {
    if (items.length === 0) {
      container.innerHTML = '<div class="nav-empty">No matches for the current search.</div>';
      return;
    }

    container.innerHTML = items
      .map((item) => {
        const isActive = state.viewType === viewType && state.viewId === item.id;
        const subtitle =
          viewType === "chapter"
            ? `${item.folder} • ${item.exampleFiles.length} examples • ${item.exercises.length} exercises`
            : `${item.path} • ${item.exampleFiles.length} entry points`;

        return `
          <button
            class="nav-button ${isActive ? "active" : ""}"
            data-view-type="${viewType}"
            data-view-id="${item.id}"
            type="button"
          >
            <span class="nav-title">${escapeHtml(item.label)}: ${escapeHtml(item.title)}</span>
            <span class="nav-subtitle">${escapeHtml(subtitle)}</span>
          </button>
        `;
      })
      .join("");
  }

  function renderNavigation() {
    navPrimaryEl.innerHTML = `
      <button
        class="nav-button ${state.viewType === "overview" ? "active" : ""}"
        data-view-type="overview"
        data-view-id="overview"
        type="button"
      >
        <span class="nav-title">Repository overview</span>
        <span class="nav-subtitle">Study workflow, chapter roadmap, and cleanup guidance</span>
      </button>
    `;

    renderNavButtons(navChaptersEl, getFilteredChapters(), "chapter");
    renderNavButtons(navSupplementalEl, getFilteredSupplemental(), "supplemental");
  }

  function renderOverview() {
    const filteredChapters = getFilteredChapters();
    const filteredSupplemental = getFilteredSupplemental();

    const chapterCards =
      filteredChapters.length === 0
        ? '<div class="empty-state">No study modules matched the current search.</div>'
        : filteredChapters
            .map((chapter) => {
              const completion = completionForExercises(chapter.exercises);
              return `
                <article class="module-card">
                  <div class="overview-tags">
                    <span class="overview-tag primary">${escapeHtml(chapter.label)}</span>
                    <span class="overview-tag">${escapeHtml(estimateStudyTime(chapter))}</span>
                  </div>
                  <h3>${escapeHtml(chapter.title)}</h3>
                  <p class="body-copy">${escapeHtml(chapter.summary)}</p>
                  <div class="module-progress" aria-hidden="true">
                    <span style="width: ${completion.percent}%;"></span>
                  </div>
                  <div class="status-line">
                    <span>${escapeHtml(`${chapter.exampleFiles.length} examples • ${chapter.exercises.length} exercises`)}</span>
                    <strong>${escapeHtml(`${completion.percent}% complete`)}</strong>
                  </div>
                  <button class="nav-button" data-view-type="chapter" data-view-id="${chapter.id}" type="button">
                    Open module
                  </button>
                </article>
              `;
            })
            .join("");

    const supplementalCards =
      filteredSupplemental.length === 0
        ? '<div class="empty-state">No supplemental guides matched the current search.</div>'
        : filteredSupplemental
            .map(
              (item) => `
                <article class="module-card">
                  <div class="overview-tags">
                    <span class="overview-tag primary">${escapeHtml(item.label)}</span>
                    <span class="overview-tag">${escapeHtml(`${item.stats.cpp} .cpp`)}</span>
                  </div>
                  <h3>${escapeHtml(item.title)}</h3>
                  <p class="body-copy">${escapeHtml(item.summary)}</p>
                  <div class="badge-row">
                    ${item.bestFor
                      .slice(0, 2)
                      .map((value) => `<span class="badge">${escapeHtml(value)}</span>`)
                      .join("")}
                  </div>
                  <button class="nav-button" data-view-type="supplemental" data-view-id="${item.id}" type="button">
                    Open folder guide
                  </button>
                </article>
              `
            )
            .join("");

    mainContentEl.innerHTML = `
      <section class="section-card">
        <p class="section-label">Study workflow</p>
        <h2 class="section-title">How to use this repository as a course website</h2>
        <p class="overview-text">
          The repo is strongest when it is treated as a three-layer learning system:
          textbook-aligned chapter folders for teaching, Programming Challenges for homework,
          and professor folders for labs, projects, and exam prep. The cleaned-up app view hides
          the tracked binaries and focuses on the material students can actually learn from.
          This repository does not currently include a <span class="inline-code">Chapter1_*</span>
          folder, so the first detailed teaching walkthrough begins with
          <span class="inline-code">Chapter2_Introduction_to_C++</span>.
        </p>
        <div class="quick-grid">
          <article class="quick-card">
            <strong>1. Learn the concept</strong>
            Read the chapter summary, outcomes, and study sequence before opening code.
          </article>
          <article class="quick-card">
            <strong>2. Inspect real examples</strong>
            Use the source preview to walk through actual files from the matching chapter folder.
          </article>
          <article class="quick-card">
            <strong>3. Practice in order</strong>
            Complete the exercise ladder from easier drills to harder integration tasks.
          </article>
          <article class="quick-card">
            <strong>4. Extend with challenges</strong>
            Use challenge banks and professor folders once the guided lesson is finished.
          </article>
        </div>
      </section>

      <section class="surface-card">
        <p class="section-label">Repository map</p>
        <h2 class="section-title">What each major folder is for</h2>
        <div class="folder-grid">
          ${COURSE_DATA.folderStrategy
            .map(
              (item) => `
                <article class="folder-card">
                  <div class="overview-tags">
                    <span class="overview-tag primary">${escapeHtml(item.name)}</span>
                    <span class="overview-tag">${escapeHtml(item.scope)}</span>
                  </div>
                  <h3>${escapeHtml(item.purpose)}</h3>
                  <p class="body-copy">${escapeHtml(item.action)}</p>
                  <div class="folder-metrics">
                    ${item.metrics.map((metric) => `<span class="folder-metric">${escapeHtml(metric)}</span>`).join("")}
                  </div>
                </article>
              `
            )
            .join("")}
        </div>
      </section>

      <section class="surface-card">
        <p class="section-label">Chapter roadmap</p>
        <h2 class="section-title">Primary study modules</h2>
        <div class="module-grid">${chapterCards}</div>
      </section>

      <section class="surface-card">
        <p class="section-label">Supplemental folders</p>
        <h2 class="section-title">Challenge banks, labs, and project material</h2>
        <div class="module-grid">${supplementalCards}</div>
      </section>

      <section class="surface-card">
        <p class="section-label">Cleanup priorities</p>
        <h2 class="section-title">What to improve in the repo itself</h2>
        <div class="summary-banner">
          <div class="summary-panel">
            <strong>Keep teaching content visible</strong>
            Surface <span class="inline-code">.cpp</span>, <span class="inline-code">.h</span>,
            <span class="inline-code">.txt</span>, and <span class="inline-code">.dat</span> files,
            but keep tracked executables out of the learning flow.
          </div>
          <div class="summary-panel">
            <strong>Reduce repo noise</strong>
            Remove <span class="inline-code">tempCodeRunnerFile.cpp</span> leftovers so students only see intentional examples.
          </div>
          <div class="summary-panel">
            <strong>Add structure later</strong>
            A generated manifest or README index would make future updates to the app much easier.
          </div>
          <div class="summary-panel">
            <strong>Organize assessment paths</strong>
            Group challenge problems by chapter when you are ready to build homework sets or quizzes.
          </div>
        </div>
      </section>
    `;
  }

  function renderExampleList(entity) {
    return entity.exampleFiles
      .map((file, index) => {
        const isActive = file.path === state.activeExamplePath;
        return `
          <article class="example-card ${isActive ? "active" : ""}">
            <div class="example-head">
              <span class="example-index">${escapeHtml(String(index + 1).padStart(2, "0"))}</span>
              <div>
                <button type="button" data-example-path="${escapeHtml(file.path)}">
                  <span class="example-file-name">${escapeHtml(file.name)}</span>
                </button>
                <p class="example-note">${escapeHtml(file.note)}</p>
              </div>
            </div>
          </article>
        `;
      })
      .join("");
  }

  function renderCodePreviewSection(file, options = {}) {
    const { sectionLabel = "Source preview", title = file.name, compact = false, includeAllLines = false } = options;
    const previewState = previewCache.get(file.path);
    let body = '<div class="placeholder-state">Loading file preview...</div>';

    if (previewState && previewState.status === "loaded") {
      const lines = previewState.text.split("\n");
      const previewLines = includeAllLines ? lines : lines.slice(0, 120);
      const wasTrimmed = lines.length > previewLines.length;

      body = `
        <div class="code-toolbar">
          <span class="badge primary">${escapeHtml(`${lines.length} lines`)}</span>
          <span class="badge secondary">${escapeHtml(file.path)}</span>
          <a href="${encodeURI(file.path)}" target="_blank" rel="noreferrer" class="badge link-pill">Open raw file</a>
        </div>
        <pre class="code-block"><code>${escapeHtml(previewLines.join("\n"))}</code></pre>
        ${
          wasTrimmed
            ? '<p class="helper-text">Preview trimmed to the first 120 lines so the lesson view stays readable.</p>'
            : ""
        }
      `;
    } else if (previewState && previewState.status === "error") {
      body = `
        <div class="placeholder-state">
          Could not load this file preview. Serve the repository through a local web server and try again.
          <br />
          <strong>Details:</strong> ${escapeHtml(previewState.message)}
        </div>
      `;
    }

    return `
      <section class="code-viewer ${compact ? "code-viewer-inline" : ""}">
        <p class="section-label">${escapeHtml(sectionLabel)}</p>
        ${title ? `<h3>${escapeHtml(title)}</h3>` : ""}
        ${body}
      </section>
    `;
  }

  function renderProgramLesson(file) {
    return `
      <div class="program-entry-detail">
        <article class="program-card">
          <div class="example-head">
            <span class="example-index">OPEN</span>
            <div>
              <span class="example-file-name">${escapeHtml(file.name)}</span>
              <p class="body-copy">${escapeHtml(file.whatItDoes || file.note)}</p>
            </div>
          </div>
          ${
            file.concepts && file.concepts.length > 0
              ? `
                <div class="badge-row">
                  ${file.concepts.map((concept) => `<span class="badge">${escapeHtml(concept)}</span>`).join("")}
                </div>
              `
              : ""
          }
          <div class="program-detail-grid">
            <div class="program-detail-block">
              <p class="mini-meta">Step-by-step guide to write the program</p>
              <ol class="steps-list">
                ${buildProgramSteps(file).map((step) => `<li>${escapeHtml(step)}</li>`).join("")}
              </ol>
            </div>
            <div class="program-detail-block">
              <p class="mini-meta">Notes</p>
              <ul class="checklist">
                ${(file.studyNotes || []).map((note) => `<li>${escapeHtml(note)}</li>`).join("")}
              </ul>
            </div>
          </div>
          ${renderCodePreviewSection(file, {
            sectionLabel: "Actual program code",
            title: "",
            compact: true,
            includeAllLines: true,
          })}
        </article>
      </div>
    `;
  }

  function renderProgramGuide(entity) {
    if (!hasProgramWalkthrough(entity)) {
      return "";
    }

    const programFiles = getDetailedProgramFiles(entity);

    return `
      <section class="surface-card">
        <p class="section-label">Program-by-program guide</p>
        <h2 class="section-title">What each program does and how to practice it</h2>
        ${
          entity.id === "ch2"
            ? `
              <p class="overview-text">
                The repo starts with <span class="inline-code">Chapter2_Introduction_to_C++</span>,
                so this section treats it as the first available coding chapter. This folder currently has
                <strong>${escapeHtml(String(programFiles.length))} C++ source programs</strong> in this repo
                (executables are excluded). Click any program to open its full lesson with writing guide, notes,
                and the actual source code.
              </p>
            `
            : `
              <p class="overview-text">
                Click any program below to open its own lesson block with writing steps, notes, and the full source code.
              </p>
            `
        }
        <div class="program-accordion">
          ${programFiles
            .map((file, index) => {
              const isActive = state.activeProgramPath === file.path;

              return `
                <details class="program-entry ${isActive ? "active" : ""}" ${isActive ? "open" : ""}>
                  <summary
                    class="program-summary-button ${isActive ? "active" : ""}"
                    data-program-path="${escapeHtml(file.path)}"
                  >
                    <span class="example-index">${escapeHtml(String(index + 1).padStart(2, "0"))}</span>
                    <span class="program-summary-copy">
                      <span class="example-file-name">${escapeHtml(file.name)}</span>
                      <span class="example-note">${escapeHtml(file.note)}</span>
                    </span>
                  </summary>
                  ${renderProgramLesson(file)}
                </details>
              `;
            })
            .join("")}
        </div>
      </section>
    `;
  }

  function renderDeepDive(entity) {
    if (!entity.deepDive) {
      return "";
    }

    return `
      <section class="surface-card">
        <p class="section-label">Chapter lab guide</p>
        <h2 class="section-title">${escapeHtml(entity.deepDive.title)}</h2>
        <p class="overview-text">${escapeHtml(entity.deepDive.intro)}</p>
        <div class="deep-grid">
          <article class="deep-card">
            <h3>Focus areas</h3>
            <div class="deep-list">
              ${entity.deepDive.focusAreas
                .map(
                  (item) => `
                    <div class="deep-list-item">
                      <strong>${escapeHtml(item.title)}</strong>
                      <p class="body-copy">${escapeHtml(item.description)}</p>
                    </div>
                  `
                )
                .join("")}
            </div>
          </article>
          <article class="deep-card">
            <h3>Common mistakes</h3>
            <ul class="checklist">
              ${entity.deepDive.commonMistakes.map((item) => `<li>${escapeHtml(item)}</li>`).join("")}
            </ul>
          </article>
          <article class="deep-card">
            <h3>Mini-project ladder</h3>
            <ul class="checklist">
              ${entity.deepDive.miniProjects.map((item) => `<li>${escapeHtml(item)}</li>`).join("")}
            </ul>
          </article>
        </div>
      </section>
    `;
  }

  function renderCodeViewer(entity, options = {}) {
    const { requireSelection = false } = options;
    const requestedPath = requireSelection ? state.activeProgramPath : state.activeExamplePath;
    const file = requestedPath
      ? entity.exampleFiles.find((candidate) => candidate.path === requestedPath) || null
      : requireSelection
        ? null
        : entity.exampleFiles[0] || null;

    if (!file) {
      return `
        <section class="code-viewer">
          <p class="section-label">Source preview</p>
          <h3>${requireSelection ? "Select a program first" : "No source preview available"}</h3>
          <div class="placeholder-state">
            ${
              requireSelection
                ? "Choose a program from the guide above to load its source preview here."
                : "This section does not have example files attached yet."
            }
          </div>
        </section>
      `;
    }

    return renderCodePreviewSection(file, { sectionLabel: "Source preview", title: file.name });
  }

  function renderExercisePanel(entity) {
    const completion = completionForExercises(entity.exercises);
    const breakdown = difficultyBreakdown(entity.exercises);

    return `
      <section class="section-card">
        <div class="detail-header">
          <div>
            <p class="section-label">Practice ladder</p>
            <h2 class="section-title">Guided student exercises</h2>
          </div>
          <div class="badge-row">
            <span class="badge primary">${escapeHtml(`${completion.done}/${completion.total} complete`)}</span>
            <span class="badge">${escapeHtml(`${breakdown.Easy || 0} easy`)}</span>
            <span class="badge">${escapeHtml(`${breakdown.Medium || 0} medium`)}</span>
            ${
              breakdown.Hard
                ? `<span class="badge secondary">${escapeHtml(`${breakdown.Hard} hard`)}</span>`
                : ""
            }
          </div>
        </div>
        <div class="exercise-grid">
          ${entity.exercises
            .map((exercise) => {
              const done = getExerciseProgress(exercise.id);
              return `
                <article class="exercise-card ${done ? "completed" : ""}">
                  <label>
                    <input type="checkbox" ${done ? "checked" : ""} data-exercise-id="${escapeHtml(exercise.id)}" />
                    <div>
                      <p class="exercise-meta">${escapeHtml(exercise.difficulty)}</p>
                      <h3>${escapeHtml(exercise.title)}</h3>
                      <p class="body-copy">${escapeHtml(exercise.prompt)}</p>
                      <p class="checklist-line"><strong>Hint:</strong> ${escapeHtml(exercise.hint)}</p>
                    </div>
                  </label>
                </article>
              `;
            })
            .join("")}
        </div>
      </section>
    `;
  }

  function renderChapterFooterNav(entity) {
    const { previous, next } = getAdjacentChapters(entity.id);

    return `
      <section class="surface-card">
        <p class="section-label">Continue studying</p>
        <div class="chapter-footer-nav">
          ${
            previous
              ? `
                <button class="footer-nav-card nav-button" data-view-type="chapter" data-view-id="${previous.id}" type="button">
                  <span>Previous chapter</span>
                  <strong>${escapeHtml(previous.label)}: ${escapeHtml(previous.title)}</strong>
                </button>
              `
              : `
                <div class="footer-nav-card">
                  <span>Previous chapter</span>
                  <strong>Start here</strong>
                </div>
              `
          }
          ${
            next
              ? `
                <button class="footer-nav-card nav-button" data-view-type="chapter" data-view-id="${next.id}" type="button">
                  <span>Next chapter</span>
                  <strong>${escapeHtml(next.label)}: ${escapeHtml(next.title)}</strong>
                </button>
              `
              : `
                <div class="footer-nav-card">
                  <span>Next chapter</span>
                  <strong>You are at the last main module</strong>
                </div>
              `
          }
        </div>
      </section>
    `;
  }

  function renderChapter(entity) {
    const outcomes = buildLearningOutcomes(entity);
    const studySequence = buildStudySequence(entity);
    const reviewChecklist = buildReviewChecklist(entity);
    const hasDetailedPrograms = hasProgramWalkthrough(entity);

    mainContentEl.innerHTML = `
      <section class="section-card">
        <div class="detail-header">
          <div>
            <p class="section-label">${escapeHtml(entity.label)} • ${escapeHtml(entity.folder)}</p>
            <h2 class="detail-title">${escapeHtml(entity.title)}</h2>
          </div>
          <div class="badge-row">
            <span class="badge">${escapeHtml(estimateStudyTime(entity))}</span>
            <span class="badge secondary">${escapeHtml(`${entity.exampleFiles.length} repo examples`)}</span>
          </div>
        </div>
        <p class="detail-summary">${escapeHtml(entity.summary)}</p>
        <p class="detail-note"><strong>Why it matters:</strong> ${escapeHtml(entity.whyItMatters)}</p>
        <div class="snapshot-grid">
          <article class="snapshot-card">
            <span class="snapshot-number">${escapeHtml(entity.topics.length)}</span>
            <span class="snapshot-label">Core ideas</span>
            <p class="body-copy">The chapter is structured around focused concepts rather than a long unbroken file list.</p>
          </article>
          <article class="snapshot-card">
            <span class="snapshot-number">${escapeHtml(entity.exampleFiles.length)}</span>
            <span class="snapshot-label">Code examples</span>
            <p class="body-copy">Use the chapter examples in order so the explanation stays progressive instead of scattered.</p>
          </article>
          <article class="snapshot-card">
            <span class="snapshot-number">${escapeHtml(entity.stats.cpp)}</span>
            <span class="snapshot-label">Source files in folder</span>
            <p class="body-copy">The full folder has enough material to support both lecture examples and self-study review.</p>
          </article>
        </div>
      </section>

      <section class="surface-card">
        <p class="section-label">Lesson structure</p>
        <h2 class="section-title">How to teach or study this module</h2>
        <div class="lesson-grid">
          <article class="lesson-card">
            <h3>Learning outcomes</h3>
            <ul>
              ${outcomes.map((item) => `<li>${escapeHtml(item)}</li>`).join("")}
            </ul>
          </article>
          <article class="lesson-card">
            <h3>Recommended study sequence</h3>
            <ul>
              ${studySequence.map((item) => `<li>${escapeHtml(item)}</li>`).join("")}
            </ul>
          </article>
          <article class="lesson-card">
            <h3>Review checklist</h3>
            <ul>
              ${reviewChecklist.map((item) => `<li>${escapeHtml(item)}</li>`).join("")}
            </ul>
          </article>
        </div>
      </section>

      <section class="surface-card">
        <p class="section-label">Core concepts</p>
        <h2 class="section-title">Key ideas inside this chapter</h2>
        <div class="topic-grid">
          ${entity.topics
            .map(
              (topic) => `
                <article class="topic-card">
                  <h3>${escapeHtml(topic.title)}</h3>
                  <p class="body-copy">${escapeHtml(topic.description)}</p>
                </article>
              `
            )
            .join("")}
        </div>
      </section>

      ${renderProgramGuide(entity)}

      ${
        hasDetailedPrograms
          ? ""
          : `
            <div class="section-divider">
              <section class="surface-card">
                <p class="section-label">Representative files</p>
                <h2 class="section-title">Teach with these repo examples</h2>
                <p class="overview-text">
                  These are the best entry points inside <span class="inline-code">${escapeHtml(entity.folder)}</span>.
                  Move through them in order and use the preview panel to annotate what the program is doing.
                </p>
                <div class="example-list">${renderExampleList(entity)}</div>
              </section>
              ${renderCodeViewer(entity)}
            </div>
          `
      }

      ${renderChapterFooterNav(entity)}
    `;
  }

  function renderSupplemental(entity) {
    mainContentEl.innerHTML = `
      <section class="section-card">
        <div class="detail-header">
          <div>
            <p class="section-label">${escapeHtml(entity.label)} • ${escapeHtml(entity.path)}</p>
            <h2 class="detail-title">${escapeHtml(entity.title)}</h2>
          </div>
          <div class="badge-row">
            <span class="badge primary">${escapeHtml(`${entity.stats.cpp} .cpp`)}</span>
            ${
              entity.stats.headers
                ? `<span class="badge">${escapeHtml(`${entity.stats.headers} headers`)}</span>`
                : ""
            }
            ${
              entity.stats.data
                ? `<span class="badge secondary">${escapeHtml(`${entity.stats.data} data files`)}</span>`
                : ""
            }
          </div>
        </div>
        <p class="detail-summary">${escapeHtml(entity.summary)}</p>
        <p class="supplement-note"><strong>Recommended use:</strong> ${escapeHtml(entity.recommendation)}</p>
        <div class="supplement-grid">
          ${entity.bestFor
            .map(
              (item) => `
                <article class="topic-card">
                  <h3>Best use case</h3>
                  <p class="body-copy">${escapeHtml(item)}</p>
                </article>
              `
            )
            .join("")}
        </div>
      </section>

      <div class="section-divider">
        <section class="surface-card">
          <p class="section-label">Folder structure</p>
          <h2 class="section-title">How this material is organized</h2>
          ${
            entity.breakdown
              ? `
                <ul class="cleanup-list">
                  ${entity.breakdown.map((item) => `<li>${escapeHtml(item)}</li>`).join("")}
                </ul>
              `
              : '<div class="placeholder-state">This folder is best treated as one broad practice bank.</div>'
          }
        </section>
        ${renderCodeViewer(entity)}
      </div>

      <section class="surface-card">
        <p class="section-label">Entry points</p>
        <h2 class="section-title">Recommended files to open first</h2>
        <div class="example-list">${renderExampleList(entity)}</div>
      </section>
    `;
  }

  async function loadPreview(path) {
    if (!path) {
      return;
    }

    const cached = previewCache.get(path);
    if (cached && (cached.status === "loaded" || cached.status === "loading" || cached.status === "error")) {
      return;
    }

    previewCache.set(path, { status: "loading" });
    const controller = new AbortController();
    const timeoutId = setTimeout(() => controller.abort(), 12000);

    try {
      const response = await fetch(encodeURI(path), { cache: "no-store", signal: controller.signal });
      if (!response.ok) {
        throw new Error(`HTTP ${response.status}`);
      }

      const text = await response.text();
      previewCache.set(path, { status: "loaded", text });
    } catch (error) {
      previewCache.set(path, {
        status: "error",
        message: error instanceof Error ? error.message : String(error),
      });
    } finally {
      clearTimeout(timeoutId);
    }

    renderMain();
  }

  function renderMain() {
    if (state.viewType === "overview") {
      renderOverview();
      return;
    }

    const entity = getEntity(state.viewType, state.viewId);

    if (!entity) {
      mainContentEl.innerHTML = '<div class="empty-state">This section could not be found.</div>';
      return;
    }

    if (state.viewType === "chapter" && hasProgramWalkthrough(entity) && !state.activeProgramPath) {
      const firstProgram = getDetailedProgramFiles(entity)[0] || null;
      if (firstProgram) {
        state.activeProgramPath = firstProgram.path;
        state.activeExamplePath = firstProgram.path;
      }
    }

    if (!state.activeExamplePath && entity.exampleFiles.length > 0) {
      state.activeExamplePath = entity.exampleFiles[0].path;
    }

    if (state.viewType === "chapter") {
      renderChapter(entity);
    } else {
      renderSupplemental(entity);
    }

    const previewPath = state.activeProgramPath || state.activeExamplePath;

    if (previewPath) {
      void loadPreview(previewPath);
    }
  }

  function bindEvents() {
    document.querySelectorAll("[data-view-type]").forEach((button) => {
      button.addEventListener("click", () => {
        const viewType = button.getAttribute("data-view-type");
        const viewId = button.getAttribute("data-view-id");
        setView(viewType, viewId);
      });
    });

    document.querySelectorAll("[data-example-path]").forEach((button) => {
      button.addEventListener("click", () => {
        state.activeExamplePath = button.getAttribute("data-example-path");
        renderMain();
      });
    });

    document.querySelectorAll("[data-program-path]").forEach((button) => {
      button.addEventListener("click", () => {
        const programPath = button.getAttribute("data-program-path");
        state.activeProgramPath = programPath;
        state.activeExamplePath = programPath;
        renderMain();
      });
    });

    document.querySelectorAll("[data-exercise-id]").forEach((checkbox) => {
      checkbox.addEventListener("change", () => {
        const exerciseId = checkbox.getAttribute("data-exercise-id");
        setExerciseProgress(exerciseId, checkbox.checked);
        render();
      });
    });

  }

  function render() {
    renderHeroStats();
    renderGlobalProgress();
    renderSearchSummary();
    renderNavigation();
    renderMain();
    bindEvents();
  }

  searchInputEl.addEventListener("input", (event) => {
    state.query = event.target.value.trim();
    render();
  });

  render();
})();
