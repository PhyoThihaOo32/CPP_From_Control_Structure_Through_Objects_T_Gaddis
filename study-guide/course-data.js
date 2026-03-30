const COURSE_DATA = {
  summary: {
    moduleCount: 17,
    chapterSources: 317,
    challengeSources: 48,
    professorSources: 159,
    compiledArtifacts: 366,
    tempFiles: 10,
  },
  folderStrategy: [
    {
      name: "Chapter* folders",
      scope: "Primary textbook syllabus",
      purpose:
        "Use these folders as the main chapter-by-chapter teaching path. They already match the course topics and contain the best examples for concept explanation.",
      action:
        "Keep them as the core of the app and surface selected .cpp, .h, .txt, and .dat files as lesson references.",
      metrics: ["256 .cpp", "41 headers", "20 data files"],
    },
    {
      name: "Programming Challenges",
      scope: "Practice bank",
      purpose:
        "This folder is the natural exercise repository. Its filenames already map to chapter numbers and problem types.",
      action:
        "Use it as a second-pass challenge section after students finish the guided chapter practice.",
      metrics: ["43 .cpp", "4 headers", "1 data file"],
    },
    {
      name: "CSC111_ProfYan",
      scope: "Beginner reinforcement",
      purpose:
        "These classworks and homeworks are useful for extra repetition on fundamentals such as conditionals, loops, arrays, functions, and early class design.",
      action:
        "Expose it as optional warm-up and review material instead of mixing it into the main textbook sequence.",
      metrics: ["78 .cpp", "2 headers", "5 data files"],
    },
    {
      name: "CSC211H_Prof_Azhar",
      scope: "Project and assignment material",
      purpose:
        "This side of the repo contains larger assignments, exam questions, and multi-file programs that are good for capstones after the chapter lessons.",
      action:
        "Present it as project-based practice and assessment prep, especially for classes, file I/O, vectors, and object-oriented design.",
      metrics: ["53 .cpp", "16 headers", "5 data files"],
    },
    {
      name: "Compiled executables",
      scope: "Repository noise",
      purpose:
        "Most folders contain tracked Mach-O executables with the same basenames as the source files. They are not useful as study content.",
      action:
        "Ignore them in the app, and consider moving them out of version control or adding a cleaner build/output strategy.",
      metrics: ["366 no-extension artifacts"],
    },
    {
      name: "tempCodeRunnerFile.cpp",
      scope: "Editor leftovers",
      purpose:
        "These files add noise and can confuse students because they do not represent intentional lessons.",
      action:
        "Remove them from the teaching path and clean them up when you are ready to tighten the repo.",
      metrics: ["10 temp files"],
    },
  ],
  cleanupRecommendations: [
    "Keep the new app focused on real source and data files; do not index compiled executables.",
    "Add a root README later with one-line compile/run instructions for each chapter sample.",
    "Consider a script that regenerates the study-guide metadata whenever new chapter files are added.",
    "Delete or ignore tempCodeRunner files so students only see intentional examples.",
    "Longer term, group challenge problems by chapter in a dedicated manifest to make practice assignment easier.",
  ],
  chapters: [
    {
      id: "ch2",
      label: "Chapter 2",
      title: "Introduction to C++",
      folder: "Chapter2_Introduction_to_C++",
      path: "../Chapter2_Introduction_to_C++",
      stats: { cpp: 3, headers: 0, data: 0 },
      summary:
        "This module is the first coding chapter available in the repository. It introduces the shape of a C++ program through small examples about variables, constants, arithmetic, output, and programming style.",
      whyItMatters:
        "Students need a small, stable starting point before they move into more complex input, expressions, and control flow. Chapter 2 is where they learn how a simple C++ file is organized and why readable code matters.",
      topics: [
        {
          title: "Program structure",
          description:
            "Read `main`, declarations, and output statements without getting lost in syntax.",
        },
        {
          title: "Variables and named constants",
          description:
            "Separate values that can change from values that should stay fixed throughout the program.",
        },
        {
          title: "Programming style",
          description:
            "Start good habits early with consistent naming, spacing, and output formatting.",
        },
      ],
      deepDive: {
        title: "Chapter 2 Beginner Guide",
        intro:
          "Chapter 2 should feel calm and readable. The point is not to impress the student with complexity. The point is to make them comfortable with variables, output, formulas, and the idea that code should be written for human readers as well as the compiler.",
        focusAreas: [
          {
            title: "Recognize the structure of `main`",
            description:
              "Students should be able to point to variable declarations, calculations, and output statements inside a very small program.",
          },
          {
            title: "Use variables and constants on purpose",
            description:
              "They should understand the difference between values that can change during execution and values that should stay fixed.",
          },
          {
            title: "Connect formulas to code",
            description:
              "A beginner should see that a math expression in English can become a simple assignment statement in C++.",
          },
          {
            title: "Treat readability as part of correctness",
            description:
              "Chapter 2 is the right time to establish naming, comments, and output labels as part of good programming rather than optional polish.",
          },
        ],
        commonMistakes: [
          "Using vague variable names like `x`, `y`, or `a1` even when the program domain is clear.",
          "Hardcoding values that should really be named constants.",
          "Printing a result without enough words for the user to understand what the number means.",
          "Writing correct arithmetic but leaving the program hard to read because formatting and naming were ignored.",
        ],
        miniProjects: [
          "Upgrade the payroll calculator with overtime, tax, and cleaner monetary output.",
          "Turn the constant example into a small circle calculator for circumference and area.",
          "Rewrite the programming-style example into a cleaner sales-summary report with totals and labels.",
        ],
      },
      exampleFiles: [
        {
          name: "program1_1_payroll_calculator.cpp",
          path: "../Chapter2_Introduction_to_C++/program1_1_payroll_calculator.cpp",
          note: "Simple variables, arithmetic, and formatted output in one program.",
          whatItDoes:
            "This program asks the user for hours worked and hourly pay, multiplies the two values, and prints the total pay earned.",
          whyThisProgramMatters:
            "It is the first real input-processing-output cycle in the repo, so it teaches the basic flow that students will keep reusing.",
          concepts: ["Keyboard input", "Variables", "Multiplication", "Console output"],
          studyNotes: [
            "All working values are declared as `double`, so fractional hours and rates are supported.",
            "The prompts and `cin` reads are paired in sequence, which makes the interaction easy to trace.",
            "The line `total_pay = hours * rate;` is the exact payroll rule in this version.",
            "No guard exists for invalid input, so bad numeric input can break the flow and should be handled in a later revision.",
            "The output prints raw numeric formatting and places `$` after the number, which is a good first style-improvement target.",
          ],
          buildSteps: [
            "Include `<iostream>` and start `main()` with a clear top-to-bottom structure.",
            "Declare `hours`, `rate`, and `total_pay` as `double` so decimal values are preserved.",
            "Prompt for hours worked, then read the value with `cin`.",
            "Prompt for hourly pay, then read the second value with `cin`.",
            "Compute gross pay using `total_pay = hours * rate;`.",
            "Print a full sentence that labels the result as earned pay, not just a bare number.",
            "Apply fixed two-decimal formatting in an improved version to make currency output easier to read.",
            "Test with integer and decimal inputs to verify the calculation behaves consistently.",
          ],
          takeaway:
            "A complete beginner program usually follows one reliable pattern: ask for input, store it in variables, process it with one rule, and print a result the user can understand.",
          codeSamples: [
            {
              title: "Input and storage setup",
              note: "Define the data the calculation needs before reading any values from the user.",
              snippet: [
                "double hours, rate, total_pay;",
                "cout << \"How many hours did you work? \" << endl;",
                "cin >> hours;",
                "cout << \"How much do you get paid per hour? \" << endl;",
                "cin >> rate;",
              ],
            },
            {
              title: "Core payroll rule",
              note: "This line captures the business logic: total pay equals hours times hourly rate.",
              snippet: [
                "total_pay = hours * rate;",
                "cout << \"This is the amount of money you earned: \"",
                "     << total_pay << \" $\" << endl;",
              ],
            },
          ],
          sampleRun: [
            "How many hours did you work?",
            "40",
            "How much do you get paid per hour?",
            "15.5",
            "This is the amount of money you earned: 620 $",
          ],
          watchFor: [
            "The current version does not validate negative hours or negative rates.",
            "The output format is not currency-friendly yet and should be standardized with two decimals.",
            "`using namespace std;` is acceptable for this beginner file but should be reconsidered in larger codebases.",
          ],
          practice: [
            {
              id: "ch2-payroll-lab-1",
              task: "Add overtime pay so hours above 40 are paid at 1.5x the base rate.",
            },
            {
              id: "ch2-payroll-lab-2",
              task: "Format gross pay with fixed two-decimal currency output and clearer labels.",
            },
            {
              id: "ch2-payroll-lab-3",
              task: "Add tax percentage input and print both gross pay and net pay.",
            },
            {
              id: "ch2-payroll-lab-4",
              task: "Reject invalid input (non-numeric, negative hours, or negative rates) with a helpful message.",
            },
            {
              id: "ch2-payroll-lab-5",
              task: "Extend the report with employee name and pay-period label using `getline` for the name.",
            },
          ],
        },
        {
          name: "program2_28_name_constant.cpp",
          path: "../Chapter2_Introduction_to_C++/program2_28_name_constant.cpp",
          note: "Shows why named constants make formulas easier to read and maintain.",
          whatItDoes:
            "This program uses named constants for PI and DIAMETER, calculates a circle circumference, and prints the result.",
          whyThisProgramMatters:
            "It is the first file where a student can see how good naming makes a formula easier to trust and easier to change later.",
          concepts: ["const values", "Formula translation", "Readable math code", "Precision with doubles"],
          studyNotes: [
            "The program defines `PI` and `DIAMETER` as constants, making the formula intent obvious at first glance.",
            "The calculation step is isolated in one assignment, which keeps math logic and output logic separate.",
            "Using `std::cout` directly is consistent with the file style and avoids namespace-wide imports.",
            "This is a clean example of replacing magic numbers with named values students can reason about.",
            "The fixed diameter is intentional for demonstration, but real programs should usually read this value from input.",
          ],
          buildSteps: [
            "Include `<iostream>` and open `main()`.",
            "Declare `PI` as a `const double` to represent the fixed mathematical constant.",
            "Declare `DIAMETER` as a second constant to keep the demonstration formula explicit.",
            "Declare `circumference` as a non-constant result variable.",
            "Compute circumference with `circumference = PI * DIAMETER;`.",
            "Print a labeled output line using `std::cout` and `std::endl`.",
            "Refactor version 2 to read diameter from user input while preserving `PI` as a constant.",
            "Refactor version 3 to calculate both circumference and area for comparison.",
          ],
          takeaway:
            "Named constants turn a formula from a mystery into an explanation. The math does not change, but the code becomes easier to trust and easier to edit later.",
          codeSamples: [
            {
              title: "Named constants",
              note: "Use `const` for values that should never change during program execution.",
              snippet: [
                "const double PI = 3.14159;",
                "const double DIAMETER = 10.0;",
                "double circumference;",
              ],
            },
            {
              title: "Readable formula translation",
              note: "The equation reads almost exactly like the math statement for circumference.",
              snippet: [
                "circumference = PI * DIAMETER;",
                "std::cout << \"The circumference is: \"",
                "          << circumference << std::endl;",
              ],
            },
          ],
          sampleRun: [
            "The circumference is: 31.4159",
          ],
          watchFor: [
            "Students can confuse diameter and radius; the formula changes depending on which value is stored.",
            "Hardcoded dimensions are fine for demonstration, but they limit reuse.",
            "If constants are poorly named, readability gains disappear even when `const` is used.",
          ],
          practice: [
            {
              id: "ch2-constant-lab-1",
              task: "Replace the hardcoded diameter with user input while keeping PI as a constant.",
            },
            {
              id: "ch2-constant-lab-2",
              task: "Extend the program to calculate area as well as circumference.",
            },
            {
              id: "ch2-constant-lab-3",
              task: "Rename every variable so another beginner can understand the formula instantly.",
            },
            {
              id: "ch2-constant-lab-4",
              task: "Compute and print radius from the diameter, then verify the circumference using radius-based math.",
            },
            {
              id: "ch2-constant-lab-5",
              task: "Move all output labels into clearer sentence-style messages with explicit units.",
            },
          ],
        },
        {
          name: "program2_30_programming_style.cpp",
          path: "../Chapter2_Introduction_to_C++/program2_30_programming_style.cpp",
          note: "Good file for discussing clean layout and beginner-friendly code organization.",
          whatItDoes:
            "This program prints a short stock-sale message, but its main teaching goal is code style: naming, spacing, and readable formatting.",
          whyThisProgramMatters:
            "It gives you a direct way to show that code can be correct and still need improvement if the naming, layout, or output wording is weak.",
          concepts: ["Readable names", "Output formatting", "Clean layout", "Beginner code hygiene"],
          studyNotes: [
            "This program intentionally keeps logic tiny so style decisions are easy to inspect.",
            "Variable names are understandable, but `avgPrices` can be renamed for clearer singular/plural meaning.",
            "The sentence output works, but wording (`per shares`) reveals why review for grammar and clarity matters.",
            "Because values are hardcoded, this file is a good stepping stone before introducing user input in style-focused exercises.",
            "Small files like this make it obvious that readability is a feature, not a cosmetic extra.",
          ],
          buildSteps: [
            "Start with `<iostream>` and a compact `main()`.",
            "Declare variables with names that communicate meaning (`sharesSold`, `averageSharePrice`, etc.).",
            "Assign initialization values in one place so readers can identify program assumptions quickly.",
            "Compose output with consistent wording and unit labels.",
            "Break long stream expressions across lines with aligned indentation.",
            "Review grammar and punctuation in output text as part of code quality.",
            "Run and verify both numeric correctness and message readability.",
            "Refactor the same file with input prompts to compare static versus interactive style.",
          ],
          takeaway:
            "Good code is not only about correct output. A short program should also communicate its purpose quickly through names, spacing, and readable output sentences.",
          codeSamples: [
            {
              title: "Clear variable naming",
              note: "Even in a tiny program, names should reveal meaning without extra explanation.",
              snippet: [
                "double shares = 220.0;",
                "double avgPrices = 14.67;",
              ],
            },
            {
              title: "Readable output composition",
              note: "Split long output lines so formatting remains easy to scan and maintain.",
              snippet: [
                "std::cout << \"There were \" << shares << \" shares sold at $\"",
                "          << avgPrices << \" per shares.\\n\";",
              ],
            },
          ],
          sampleRun: [
            "There were 220 shares sold at $14.67 per shares.",
          ],
          watchFor: [
            "Readable code can still produce awkward user text if output wording is not reviewed.",
            "Names that are close but slightly inaccurate become confusing as programs grow.",
            "Hardcoded values hide assumptions and reduce testability.",
          ],
          practice: [
            {
              id: "ch2-style-lab-1",
              task: "Rewrite the output so it reads like a clean financial sentence with labels and totals.",
            },
            {
              id: "ch2-style-lab-2",
              task: "Add a new variable for total sale amount and print it on its own line.",
            },
            {
              id: "ch2-style-lab-3",
              task: "Refactor the variable names and comments to make the file easier to read in under 20 seconds.",
            },
            {
              id: "ch2-style-lab-4",
              task: "Replace hardcoded values with user input and keep the same output style quality.",
            },
            {
              id: "ch2-style-lab-5",
              task: "Convert output to a mini two-line report: shares, average price, and total value with aligned labels.",
            },
          ],
        },
      ],
      exercises: [
        {
          id: "ch2-overtime-payroll",
          title: "Expand the payroll calculator",
          difficulty: "Easy",
          prompt:
            "Add overtime pay and a tax deduction to the payroll example, then print gross pay and net pay.",
          hint:
            "Start from `program1_1_payroll_calculator.cpp` and introduce named constants for rates.",
        },
        {
          id: "ch2-temperature-converter",
          title: "Write a small converter",
          difficulty: "Easy",
          prompt:
            "Create a Fahrenheit-to-Celsius converter that reads one value and prints a labeled result.",
          hint:
            "Use clear variable names and keep the output sentence readable.",
        },
        {
          id: "ch2-style-review",
          title: "Refactor for style",
          difficulty: "Easy",
          prompt:
            "Take one beginner program and rename variables, align spacing, and improve the output labels without changing the logic.",
          hint:
            "Use `program2_30_programming_style.cpp` as a checklist for what better code presentation looks like.",
        },
        {
          id: "ch2-circle-report",
          title: "Turn the constant example into a calculator",
          difficulty: "Easy",
          prompt:
            "Read a diameter from the user, keep PI as a constant, and print both circumference and area with clearer labels.",
          hint:
            "This is the natural extension of `program2_28_name_constant.cpp`.",
        },
        {
          id: "ch2-pay-statement",
          title: "Write a cleaner pay statement",
          difficulty: "Medium",
          prompt:
            "Extend the payroll program so it prints a small pay statement with employee name, hours, rate, and total pay on separate lines.",
          hint:
            "Focus on readability as much as the arithmetic. Chapter 2 is about writing code other people can understand.",
        },
      ],
    },
    {
      id: "ch3",
      label: "Chapter 3",
      title: "Expressions and Interactivity",
      folder: "Chapter3_Expression_And_Interactivity",
      path: "../Chapter3_Expression_And_Interactivity",
      stats: { cpp: 13, headers: 0, data: 0 },
      summary:
        "This chapter is where the programs stop being static examples and start reacting to the user. It introduces keyboard input, safer text input, type conversion, output formatting, math functions, randomness, and small interactive calculations.",
      whyItMatters:
        "Most beginner programs become useful only after they can read data, compute with it correctly, and present results in a clean way. Chapter 3 is the shift from passive code to interactive programs.",
      topics: [
        {
          title: "Console input patterns",
          description:
            "Use `cin`, `getline`, and input cleanup correctly when collecting user data without skipped prompts or broken reads.",
        },
        {
          title: "Arithmetic and type conversion",
          description:
            "Control integer division, overflow risk, unit meaning, and explicit casts so numeric results stay correct.",
        },
        {
          title: "Output formatting and randomness",
          description:
            "Use manipulators, precision, tables, and random values to make console programs feel polished and testable.",
        },
      ],
      deepDive: {
        title: "Chapter 3 Teaching Guide",
        intro:
          "Chapter 3 works best when taught as a progression: first collect input, then clean up input, then control numeric results, and finally make output look intentional. The programs in this folder are short, but together they introduce habits that students will keep using for the rest of the book.",
        focusAreas: [
          {
            title: "Read values safely",
            description:
              "Start with `cin` for numbers, then contrast it with `getline` for names, cities, and any data that can contain spaces.",
          },
          {
            title: "Control numeric behavior",
            description:
              "Use type casting to avoid accidental integer division and talk about overflow as a warning that every type has limits.",
          },
          {
            title: "Format output with intent",
            description:
              "Teach `setprecision`, `fixed`, and `setw` as readability tools, not as decoration.",
          },
          {
            title: "Build simple interactive models",
            description:
              "Use crates, inventory, dice, and reading plans as examples of how formulas and user input become useful programs.",
          },
        ],
        commonMistakes: [
          "Using `cin` for full names or cities and then wondering why only the first word is stored.",
          "Forgetting that integer division drops the decimal part unless one side is converted to `double`.",
          "Using output labels or units that do not match the calculation, such as area printed with cubic units.",
          "Calling `rand()` without thinking about seeding or value range.",
          "Formatting output only after the final line instead of setting the stream once before a whole table or report.",
        ],
        miniProjects: [
          "Build a clean receipt generator that reads item name, quantity, and unit price, then prints a formatted receipt.",
          "Create a study planner that reads books and months, then uses type casting to report an average per month.",
          "Write a shipping quote calculator based on the crate example but with user-selected pricing tiers.",
          "Make a small text-based game that rolls dice, reports totals, and repeats until the user quits.",
        ],
      },
      exampleFiles: [
        {
          name: "program3_1_cin_object.cpp",
          path: "../Chapter3_Expression_And_Interactivity/program3_1_cin_object.cpp",
          note: "Foundational numeric-input example using `cin`.",
          whatItDoes:
            "This program asks the user for the length and width of a rectangle, multiplies the two values, and prints the rectangle's area.",
          whyThisProgramMatters:
            "It is usually the student's first real input-driven calculation in the repo, so it is the right place to establish the rhythm of prompt, read, compute, print.",
          concepts: ["`cin` input", "Variables", "Stored calculation", "Output message"],
          studyNotes: [
            "The program collects two numeric values before doing any calculation.",
            "The expression `area = length * width` is the central idea: inputs become a derived result.",
            "The final label prints `m3`, which is a useful teaching point because area should normally use square units instead of cubic units.",
          ],
          buildSteps: [
            "Start with the standard header and `main()` so the program has a clear structure.",
            "Declare variables for length, width, and area before asking the user for any values.",
            "Prompt for the rectangle length and read it with `cin`.",
            "Prompt for the rectangle width and read the second value with `cin`.",
            "Multiply length by width and store the answer in `area`.",
            "Print the area with a label and fix the unit so the result reads like square measure instead of cubic measure.",
          ],
          takeaway:
            "This program teaches the basic shape of an interactive formula: gather the inputs first, compute one clear result, and print it with wording that matches the math.",
          sampleRun: [
            "This program calculate the area of a rectangle in meter.",
            "What is the length of the rectanlge? 5",
            "What is the width of the rectangle? 3",
            "Area of the rectangle is 15m3",
          ],
          watchFor: [
            "Students often focus on syntax and miss that the output unit should be improved.",
            "This is a good file for discussing prompt wording and output clarity.",
          ],
          practice: [
            { id: "ch3-cin-rect-1", task: "Fix the unit label so the result is described more accurately." },
            { id: "ch3-cin-rect-2", task: "Add perimeter as a second calculation and print both results." },
            { id: "ch3-cin-rect-3", task: "Rename the prompts so they sound more polished and consistent." },
          ],
        },
        {
          name: "p3_19_getline.cpp",
          path: "../Chapter3_Expression_And_Interactivity/p3_19_getline.cpp",
          note: "Full-line string input with `getline`.",
          whatItDoes:
            "This program reads a person's full name and city using `getline`, then prints both pieces of text back to the user.",
          whyThisProgramMatters:
            "It teaches when `getline` is the correct tool and prevents the common beginner problem of losing everything after the first space.",
          concepts: ["`getline`", "String variables", "Full-line input", "Multi-line output"],
          studyNotes: [
            "Unlike `cin >>`, `getline` keeps reading until Enter is pressed, so spaces are preserved.",
            "The program is simple on purpose so students can focus on the input method, not the formula.",
            "This file pairs naturally with `pg3_23_cin_get_ignore.cpp` when mixed input starts causing trouble.",
          ],
          buildSteps: [
            "Include the string header and create string variables for the name and city.",
            "Print a prompt asking for the full name instead of just one word.",
            "Use `getline` to read the entire line into the name variable.",
            "Print a second prompt for the city and use `getline` again so spaces are preserved there too.",
            "Store both complete lines exactly as the user typed them.",
            "Print the greeting and city message back in a clean multi-line response.",
          ],
          takeaway:
            "Use `getline` when the input can contain spaces. That decision alone prevents one of the most common beginner input bugs.",
          sampleRun: [
            "Please enter your name:",
            "Ada Lovelace",
            "Please enter the city you live in:",
            "New York",
            "Hello Ada Lovelace",
            "You live in New York",
          ],
          watchFor: [
            "Students often switch to `getline` too late, after already reading numeric input with `cin` and leaving a newline behind.",
          ],
          practice: [
            { id: "ch3-getline-1", task: "Add a third `getline` prompt for the user's favorite course or hobby." },
            { id: "ch3-getline-2", task: "Print the greeting in one formatted paragraph instead of two short lines." },
            { id: "ch3-getline-3", task: "Turn this into a profile card that also asks for school or street address." },
          ],
        },
        {
          name: "pg3_23_cin_get_ignore.cpp",
          path: "../Chapter3_Expression_And_Interactivity/pg3_23_cin_get_ignore.cpp",
          note: "Input-cleanup example with `cin.ignore()` and `cin.get()`.",
          whatItDoes:
            "This program reads a name and age, clears the leftover newline with `cin.ignore()`, then waits for the user to press Enter before displaying the stored data.",
          whyThisProgramMatters:
            "This is the first file in the repo that directly addresses the keyboard-buffer problem students hit when they mix formatted input with line-based input.",
          concepts: ["Input buffer", "`cin.ignore()`", "`cin.get()`", "Mixed input debugging"],
          studyNotes: [
            "After `cin >> age`, the newline from pressing Enter is still in the buffer.",
            "Calling `cin.ignore()` skips that newline so the next character read behaves as expected.",
            "This is less about the specific program output and more about understanding why later prompts sometimes seem to skip themselves.",
          ],
          buildSteps: [
            "Declare the variables for the user's name and age before reading input.",
            "Read the name and age in the order shown by the program prompts.",
            "Notice that pressing Enter after the age leaves a newline character in the input buffer.",
            "Call `cin.ignore()` to remove that leftover newline before the next character-based read happens.",
            "Use `cin.get()` or the program's pause step to wait for a clean Enter press from the user.",
            "Print the saved name and age so students can see that the data stayed intact after buffer cleanup.",
          ],
          takeaway:
            "The real lesson is not the pause itself. It is understanding that formatted input leaves characters behind, and those characters must sometimes be cleared deliberately.",
          sampleRun: [
            "Enter your name >>",
            "Grace Hopper",
            "Enter your age >>",
            "20",
            "Press Enter.",
            "Name:   Grace Hopper",
            "Age:    20",
          ],
          watchFor: [
            "If students do not understand the leftover newline, they tend to memorize `ignore()` without knowing why it is needed.",
          ],
          practice: [
            { id: "ch3-ignore-1", task: "Modify the program so it reads a full name after the age without skipping the prompt." },
            { id: "ch3-ignore-2", task: "Remove the Enter-check loop and replace it with a simpler pause design." },
            { id: "ch3-ignore-3", task: "Write a second version that asks for age first, then name, and still works correctly." },
          ],
        },
        {
          name: "program3_9_typecasting.cpp",
          path: "../Chapter3_Expression_And_Interactivity/program3_9_typecasting.cpp",
          note: "Concrete example of controlling numeric conversion with `static_cast`.",
          whatItDoes:
            "This program asks how many books the user plans to read and how many months they will take, then calculates the average number of books per month using type casting.",
          whyThisProgramMatters:
            "It introduces one of the most important beginner habits in C++: converting a value on purpose so arithmetic behaves the way you intend.",
          concepts: ["`static_cast<double>`", "Integer division", "Average calculation", "Planning formula"],
          studyNotes: [
            "Without the cast, `books / months` would use integer division and lose the decimal part.",
            "The cast is placed only where it is needed, which keeps the rest of the variables simple.",
            "This is a strong file for teaching the difference between storing integers and computing decimal results.",
          ],
          buildSteps: [
            "Declare integer variables for the number of books and the number of months.",
            "Prompt the user for both values and read them with `cin`.",
            "Create a result variable that can store a decimal average.",
            "Use `static_cast<double>` on one side of the division so the average is computed in floating-point form.",
            "Store the monthly reading rate in the result variable instead of printing the formula directly.",
            "Print the average in a sentence that makes the unit clear, such as books per month.",
          ],
          takeaway:
            "A `double` result variable is not enough by itself. If the division starts as integer math, the decimal information is already lost before assignment.",
          sampleRun: [
            "How many books do you plan to read?",
            "10",
            "How many months will it take you to read them?",
            "3",
            "That's 3.33333 books per month.",
          ],
          watchFor: [
            "Students often think assigning the result to a `double` is enough, but the division happens before the assignment.",
          ],
          practice: [
            { id: "ch3-cast-1", task: "Add a yearly total estimate based on the monthly reading rate." },
            { id: "ch3-cast-2", task: "Protect against entering 0 months and print a helpful error message." },
            { id: "ch3-cast-3", task: "Reuse this pattern in a miles-per-day or pages-per-week calculator." },
          ],
        },
        {
          name: "p3_15_setprecision_manipulator.cpp",
          path: "../Chapter3_Expression_And_Interactivity/p3_15_setprecision_manipulator.cpp",
          note: "Shows how `setprecision` changes floating-point display.",
          whatItDoes:
            "This program divides two fixed decimal values and prints the quotient multiple times with different precision settings.",
          whyThisProgramMatters:
            "It separates the stored numeric value from the way that value is displayed, which is a key idea for readable output.",
          concepts: ["`setprecision`", "Floating-point display", "Significant digits", "Formatted output"],
          studyNotes: [
            "The same calculated quotient is printed several times, but it looks different because the stream formatting changes.",
            "This is a display tool, not a way to increase the actual accuracy stored in the variable.",
            "It sets up the next step of using `fixed` when students want a fixed number of digits after the decimal point.",
          ],
          buildSteps: [
            "Declare the decimal values and compute the quotient once at the top of the program.",
            "Print the original result first so there is a baseline for comparison.",
            "Apply `setprecision` with one value and print the quotient again.",
            "Change the precision setting and print the same quotient another time.",
            "Compare the outputs to show that the stored number stayed the same while only the display changed.",
            "Explain which versions are useful for human reading and which are excessive for everyday output.",
          ],
          takeaway:
            "Precision settings control presentation, not the underlying math. The program is a display lesson before it is a calculation lesson.",
          sampleRun: [
            "5.53008",
            "5.5301",
            "5.5300796260474427856...",
          ],
          watchFor: [
            "Asking for very high precision does not create more true mathematical accuracy than the type already stores.",
          ],
          practice: [
            { id: "ch3-precision-1", task: "Change the numbers and compare how many useful digits still look trustworthy." },
            { id: "ch3-precision-2", task: "Print the same value with precision 2, 4, and 6, then explain the difference." },
          ],
        },
        {
          name: "p3_16_fixed_manipulator.cpp",
          path: "../Chapter3_Expression_And_Interactivity/p3_16_fixed_manipulator.cpp",
          note: "Formats a three-day sales report with `fixed`, `setprecision`, and `setw`.",
          whatItDoes:
            "This program reads three daily sales values, totals them, and prints a more polished sales table with aligned columns and fixed decimal places.",
          whyThisProgramMatters:
            "It is the first Chapter 3 program that makes output look intentional instead of merely correct.",
          concepts: ["`fixed`", "`setprecision`", "`setw`", "Table-like output"],
          studyNotes: [
            "The formatting settings are applied once and then reused for the whole report.",
            "This file shows that readability is part of programming, not something added at the end if there is time.",
            "It is a good bridge from raw calculations to report-style output.",
          ],
          buildSteps: [
            "Declare variables for each day's sales and for the final total.",
            "Read the three sales amounts from the user in order.",
            "Add the three values together and store the result in a total variable.",
            "Set `fixed`, `setprecision`, and width formatting before printing the report lines.",
            "Print each day's value using the same alignment pattern so the table looks consistent.",
            "Print the total as the final line of the report using the exact same formatting style.",
          ],
          takeaway:
            "Formatting belongs to program design, not decoration. A clear report helps users trust the result and helps programmers see mistakes faster.",
          sampleRun: [
            "Enter the sales for day 1: 123.45",
            "Enter the sales for day 2: 210.5",
            "Enter the sales for day3; 50",
            "",
            "-----Sales Figures-----",
            "Day 1:   123.4500",
            "Day 2:   210.5000",
            "Day 3:    50.0000",
            "Total:   383.9500",
          ],
          watchFor: [
            "Students often use formatting one line too late, after some output has already been printed in a different style.",
          ],
          practice: [
            { id: "ch3-fixed-1", task: "Add an average-sales line below the total using the same formatting style." },
            { id: "ch3-fixed-2", task: "Turn the three-day report into a five-day report." },
            { id: "ch3-fixed-3", task: "Add dollar signs and better column labels without breaking the alignment." },
          ],
        },
        {
          name: "p3_24_math_function.cpp",
          path: "../Chapter3_Expression_And_Interactivity/p3_24_math_function.cpp",
          note: "Uses math-library functions to compute a hypotenuse.",
          whatItDoes:
            "This program asks for the two shorter sides of a right triangle, then uses `pow` and `sqrt` to compute the hypotenuse.",
          whyThisProgramMatters:
            "It is a clean example of translating a familiar math formula into C++ code with library support.",
          concepts: ["`sqrt`", "`pow`", "Formula translation", "Math library"],
          studyNotes: [
            "The expression mirrors the Pythagorean theorem closely, which makes it easier to read and verify.",
            "This is a good place to discuss why libraries exist: they prevent students from reinventing common operations.",
            "The result is formatted with `setprecision`, which reinforces Chapter 3 output control.",
          ],
          buildSteps: [
            "Include the math header so the program can use `pow` and `sqrt`.",
            "Declare variables for side `a`, side `b`, and the final hypotenuse.",
            "Read the two shorter side lengths from the user.",
            "Use `pow` to square each side and add the two squared values together.",
            "Apply `sqrt` to that sum and store the answer as the hypotenuse.",
            "Print the result with a label that clearly identifies it as the triangle's hypotenuse.",
          ],
          takeaway:
            "Math-library functions make code shorter and clearer when the formula already exists in standard mathematics.",
          sampleRun: [
            "Enter the length of the side a: 3",
            "Enter the length of the side b: 4",
            "The length of the hypotenuse is: 5",
          ],
          watchFor: [
            "Students sometimes forget to include `<cmath>` and then wonder why the math functions are not found.",
          ],
          practice: [
            { id: "ch3-math-1", task: "Extend the program to also calculate triangle perimeter." },
            { id: "ch3-math-2", task: "Round the output more cleanly for a user-facing result." },
            { id: "ch3-math-3", task: "Adapt the file into a distance-formula calculator for two points." },
          ],
        },
        {
          name: "program3_11_inventory_check.cpp",
          path: "../Chapter3_Expression_And_Interactivity/program3_11_inventory_check.cpp",
          note: "Tracks three stores from one beginning inventory.",
          whatItDoes:
            "This program asks for a beginning inventory value, assigns that same starting amount to three stores, subtracts each store's sales, and prints the updated inventory list.",
          whyThisProgramMatters:
            "It shows how one input can be reused across multiple variables and how a small interactive model can represent a real business scenario.",
          concepts: ["Multiple assignment", "State updates", "Repeated input", "Simple reporting"],
          studyNotes: [
            "The line `store1 = store2 = store3 = begInv;` is the key setup pattern in this file.",
            "Each store is updated independently after sharing the same starting value.",
            "This is a useful stepping stone toward loops and arrays later in the book.",
          ],
          buildSteps: [
            "Declare variables for the beginning inventory, each store inventory, and the reused sales input.",
            "Read the starting inventory from the user once.",
            "Assign that same starting value to all three store variables in one setup step.",
            "Ask how many widgets each store sold and subtract each sale from the matching store variable.",
            "Repeat the update pattern carefully so every store's state changes independently.",
            "Print the updated inventory report with one labeled line per store.",
          ],
          takeaway:
            "One input can initialize several related values, but each value can still evolve separately after the program starts updating state.",
          sampleRun: [
            "What was the beginning inventory for the stores?",
            "100",
            "How many widget has store 1 sold?",
            "25",
            "How many widget has store 2 sold?",
            "10",
            "How many widget has store 3 sold?",
            "30",
            "-----Here is the updated store inventory List-----",
            "Store 1: 75",
            "Store 2: 90",
            "Store 3: 70",
          ],
          watchFor: [
            "Students often miss the idea that the same variable `sold` is intentionally reused for each store.",
          ],
          practice: [
            { id: "ch3-inventory-1", task: "Add a final total inventory across all stores." },
            { id: "ch3-inventory-2", task: "Warn the user if a store sold more widgets than it started with." },
            { id: "ch3-inventory-3", task: "Add a fourth store without copying the output style incorrectly." },
          ],
        },
        {
          name: "pg3_25_random.cpp",
          path: "../Chapter3_Expression_And_Interactivity/pg3_25_random.cpp",
          note: "Introduces seeding and ranged random numbers.",
          whatItDoes:
            "This program seeds the random number generator with the current time, prints a few raw random values, then generates one random value inside a chosen range from 0 to 100.",
          whyThisProgramMatters:
            "It gives students the first building block for games, simulations, and repeatable random-choice exercises.",
          concepts: ["`rand`", "`srand`", "`time(0)`", "Random range formula"],
          studyNotes: [
            "Seeding the generator changes the sequence each time the program runs.",
            "The range formula is the part students will reuse most often in later programs.",
            "This file is a foundation, not a finished application on its own.",
          ],
          buildSteps: [
            "Include the headers needed for random numbers and current time.",
            "Seed the generator with `srand(time(0))` near the start of `main()`.",
            "Print a few raw `rand()` values first so students can see the unbounded form.",
            "Choose the target range the program wants, such as 0 through 100.",
            "Use the range formula to convert a raw random value into that smaller interval.",
            "Print the ranged result and explain that the exact number changes but the boundaries should stay correct.",
          ],
          takeaway:
            "Random programming has two parts: seed the generator once, then map the result into the range your application actually needs.",
          sampleRun: [
            "Example output (your values will vary):",
            "1330059215 62124417 1871135010",
            "42",
          ],
          watchFor: [
            "If the generator is not seeded, students may think the program is broken because it repeats the same pattern.",
          ],
          practice: [
            { id: "ch3-random-1", task: "Change the range so the random number is between 1 and 6." },
            { id: "ch3-random-2", task: "Generate three ranged random values instead of one." },
            { id: "ch3-random-3", task: "Turn the file into a number-guessing setup that secretly picks one value." },
          ],
        },
        {
          name: "p3_26_two_dice.cpp",
          path: "../Chapter3_Expression_And_Interactivity/p3_26_two_dice.cpp",
          note: "A compact dice simulation built on the random-number formula.",
          whatItDoes:
            "This program seeds the random generator, rolls two dice by producing two values between 1 and 6, and prints both outcomes.",
          whyThisProgramMatters:
            "It is the first Chapter 3 program that feels like a game and is an ideal follow-up after the basic random-number demo.",
          concepts: ["Random range 1-6", "Constants", "Simulation", "Game-like output"],
          studyNotes: [
            "The constants make the dice range easier to read than embedding raw numbers everywhere.",
            "This is a good place to discuss what makes a program reusable: clear range values and predictable structure.",
            "Students can immediately extend this into totals, win conditions, or repeated rounds.",
          ],
          buildSteps: [
            "Include the random and time headers, then seed the generator once at the start.",
            "Declare constants or clearly named values for the smallest and largest die faces.",
            "Generate the first die value using the random range formula for 1 through 6.",
            "Generate the second die value using the same formula.",
            "Store each die in its own variable so the outputs can be printed clearly.",
            "Print both dice with labels and verify that each result stays inside the expected range.",
          ],
          takeaway:
            "A small simulation becomes readable when the random range is named clearly and each generated value has an obvious purpose.",
          sampleRun: [
            "Rolling Rolling ...",
            "Dice 1: 4",
            "Dice 2: 6",
          ],
          watchFor: [
            "Values will vary between runs, so students should verify the range and structure rather than exact numbers.",
          ],
          practice: [
            { id: "ch3-dice-1", task: "Print the sum of both dice below the roll." },
            { id: "ch3-dice-2", task: "Add a message for doubles such as 'You rolled a pair!'." },
            { id: "ch3-dice-3", task: "Wrap the program in a loop so the user can roll again." },
          ],
        },
        {
          name: "p3_28_crates.cpp",
          path: "../Chapter3_Expression_And_Interactivity/p3_28_crates.cpp",
          note: "A richer applied program using constants, input, formulas, and formatting.",
          whatItDoes:
            "This program asks for crate dimensions, calculates volume, build cost, charge, and profit, then prints a formatted quote-style summary.",
          whyThisProgramMatters:
            "It combines several Chapter 3 ideas into one practical mini-application, making it one of the best files in the folder for synthesis practice.",
          concepts: ["Named constants", "Multiple formulas", "Fixed decimal output", "Business-style reporting"],
          studyNotes: [
            "The file is longer than the earlier examples because it models a slightly more realistic scenario.",
            "Constants are used for pricing rules, which makes the business logic easier to update later.",
            "This is a strong file for teaching the value of grouping related calculations together before printing the report.",
          ],
          buildSteps: [
            "Declare constants for the pricing rules and variables for the crate dimensions and computed values.",
            "Prompt for length, width, and height, then store each dimension from user input.",
            "Multiply the dimensions to calculate the crate volume first.",
            "Use the constants and volume to compute the build cost, customer charge, and resulting profit.",
            "Apply fixed decimal formatting before printing the financial summary.",
            "Print the quote in a logical order: volume, cost, charge, and then profit.",
          ],
          takeaway:
            "This file shows how a larger beginner program stays manageable: constants define the rules, intermediate variables hold each result, and the final report prints the story in order.",
          sampleRun: [
            "Enter length: 3",
            "Enter width: 2",
            "Enter height: 4",
            "Total Volume of the crate is 24.00",
            "It will cost 5.52$.",
            "We will charge you 12.00 $.",
            "We made 6.48$ profit.",
          ],
          watchFor: [
            "Students should keep the order of calculations clear: volume first, then cost and charge, then profit.",
          ],
          practice: [
            { id: "ch3-crate-1", task: "Add a shipping fee based on total volume." },
            { id: "ch3-crate-2", task: "Ask for the customer's name and print it at the top of the quote." },
            { id: "ch3-crate-3", task: "Offer two different charge rates and let the user choose one." },
          ],
        },
        {
          name: "program3_7_overflow_underflow.cpp",
          path: "../Chapter3_Expression_And_Interactivity/program3_7_overflow_underflow.cpp",
          note: "Demonstrates what happens when values move beyond a type's range.",
          whatItDoes:
            "This program shows integer overflow and underflow with a `short`, then performs floating-point operations meant to demonstrate overflow and underflow behavior.",
          whyThisProgramMatters:
            "It teaches that data types have limits and that not every arithmetic operation is safe just because the syntax compiles.",
          concepts: ["Type limits", "Overflow", "Underflow", "Numeric caution"],
          studyNotes: [
            "This is a demonstration file, not a model for business logic.",
            "The important lesson is that every type has a limited range, so choosing a type matters.",
            "Use this file to start a discussion about why testing extreme values is important.",
          ],
          buildSteps: [
            "Declare a small integer type such as `short` and assign it a value close to its upper limit.",
            "Add to that value so the program demonstrates overflow behavior.",
            "Move near the lower limit and subtract so the program also demonstrates underflow behavior.",
            "Create floating-point examples meant to show extreme large and small results.",
            "Print each stage with labels so the reader can match the output to the operation that caused it.",
            "Discuss the results as warnings about type limits rather than patterns to depend on in real code.",
          ],
          takeaway:
            "Compilation success does not guarantee safe arithmetic. Type limits are part of program correctness, especially when inputs or calculations can grow unexpectedly.",
          watchFor: [
            "Do not treat this program's exact wraparound behavior as something to rely on in real application logic.",
            "The float results are machine-dependent enough that the idea matters more than the exact printed numbers.",
          ],
          practice: [
            { id: "ch3-overflow-1", task: "Change the type and compare how the range behavior changes." },
            { id: "ch3-overflow-2", task: "Add comments explaining which lines are demonstration-only and why." },
          ],
        },
      ],
      exercises: [
        {
          id: "ch3-receipt-generator",
          title: "Build a mini receipt generator",
          difficulty: "Easy",
          prompt:
            "Read an item name, quantity, and price, then print a formatted receipt with subtotal and tax.",
          hint:
            "Mix `getline` for the item name with numeric input for the rest of the fields.",
        },
        {
          id: "ch3-dice-simulator",
          title: "Simulate rolling dice",
          difficulty: "Medium",
          prompt:
            "Create a two-dice game that prints both dice values and their total, then repeat for multiple rolls.",
          hint:
            "Use `pg3_25_random.cpp` and `p3_26_two_dice.cpp` as a starting point.",
        },
        {
          id: "ch3-input-debugging",
          title: "Fix mixed-input issues",
          difficulty: "Medium",
          prompt:
            "Write a program that asks for a full name and age without skipping prompts or leaving newline problems behind.",
          hint:
            "Look at `pg3_23_cin_get_ignore.cpp` and compare it to `p3_19_getline.cpp`.",
        },
        {
          id: "ch3-sales-report",
          title: "Build a polished sales report",
          difficulty: "Medium",
          prompt:
            "Ask for sales across several days and print a fixed-width, fixed-decimal report with a total and average.",
          hint:
            "Use the formatting patterns from `p3_16_fixed_manipulator.cpp` instead of printing raw doubles.",
        },
        {
          id: "ch3-hypotenuse-tool",
          title: "Extend the math-function example",
          difficulty: "Medium",
          prompt:
            "Turn the hypotenuse program into a triangle helper that also prints perimeter and checks for valid positive side lengths.",
          hint:
            "Keep the formula section separate from the input and output sections.",
        },
        {
          id: "ch3-crate-quote",
          title: "Create a better crate quote calculator",
          difficulty: "Hard",
          prompt:
            "Use the crate program as a base and add customer name, shipping fee, and a cleaner final quote layout.",
          hint:
            "This is a Chapter 3 synthesis problem: constants, input, formulas, and formatting all belong together.",
        },
        {
          id: "ch3-reading-planner",
          title: "Make a reading planner",
          difficulty: "Easy",
          prompt:
            "Ask for total books, months, and pages per book, then print the average books per month and pages per month using the correct numeric types.",
          hint:
            "Use `static_cast<double>` when the result should keep its decimal part.",
        },
      ],
    },
    {
      id: "ch4",
      label: "Chapter 4",
      title: "Decision Making and Relational Operations",
      folder: "Chapter4_Relational_Operation",
      path: "../Chapter4_Relational_Operation",
      stats: { cpp: 22, headers: 0, data: 0 },
      summary:
        "Students learn boolean logic, relational operators, `if` statements, `switch`, menus, and defensive condition checks.",
      whyItMatters:
        "Branching is what turns a calculator into a decision-making program.",
      topics: [
        {
          title: "Boolean expressions",
          description:
            "Evaluate conditions with relational and logical operators instead of guessing how comparisons behave.",
        },
        {
          title: "Selection statements",
          description:
            "Choose between `if`, `if/else`, and `switch` depending on the structure of the problem.",
        },
        {
          title: "Validation and menus",
          description:
            "Prevent bad inputs and give users clear choices through structured decision logic.",
        },
      ],
      exampleFiles: [
        {
          name: "pg4_1_true_false.cpp",
          path: "../Chapter4_Relational_Operation/pg4_1_true_false.cpp",
          note: "Introduces boolean results from comparisons.",
        },
        {
          name: "pg4_10_loan_qualification_check.cpp",
          path: "../Chapter4_Relational_Operation/pg4_10_loan_qualification_check.cpp",
          note: "Useful for combining multiple conditions in a real decision.",
        },
        {
          name: "pg4_18_menu_driven_program.cpp",
          path: "../Chapter4_Relational_Operation/pg4_18_menu_driven_program.cpp",
          note: "Clear example of user-choice branching.",
        },
        {
          name: "pg4_23_switch.cpp",
          path: "../Chapter4_Relational_Operation/pg4_23_switch.cpp",
          note: "Good for contrasting `switch` with long `if/else` chains.",
        },
      ],
      exercises: [
        {
          id: "ch4-grade-classifier",
          title: "Create a grade classifier",
          difficulty: "Easy",
          prompt:
            "Read a numeric score and print the letter grade plus a pass/fail message.",
          hint:
            "Use ordered conditions so only one grade branch can run.",
        },
        {
          id: "ch4-menu-calculator",
          title: "Write a menu-based calculator",
          difficulty: "Medium",
          prompt:
            "Offer add, subtract, multiply, and divide operations in a menu and validate divide-by-zero cases.",
          hint:
            "Model the menu structure on `pg4_18_menu_driven_program.cpp`.",
        },
        {
          id: "ch4-validation-lab",
          title: "Improve input validation",
          difficulty: "Medium",
          prompt:
            "Take a conditional example and add range checks plus a helpful error message for invalid data.",
          hint:
            "Loan qualification and test score files are good places to practice defensive logic.",
        },
      ],
    },
    {
      id: "ch5a",
      label: "Chapter 5A",
      title: "Loops and Iteration",
      folder: "Chapter5_Loops_And_Files",
      path: "../Chapter5_Loops_And_Files",
      stats: { cpp: 16, headers: 0, data: 0 },
      summary:
        "This module focuses on repetition with `while`, `do-while`, `for`, nested loops, sentinels, and control statements.",
      whyItMatters:
        "Students need loop fluency before they can process arrays, files, or repeated calculations.",
      topics: [
        {
          title: "Loop selection",
          description:
            "Choose the right loop based on whether the count is known up front or driven by a condition.",
        },
        {
          title: "Accumulators and sentinels",
          description:
            "Track totals, counts, and stop conditions without off-by-one errors.",
        },
        {
          title: "Nested patterns",
          description:
            "Use nested loops for tables, clocks, and repeated row/column output.",
        },
      ],
      exampleFiles: [
        {
          name: "pg5_3_simple_while_loop.cpp",
          path: "../Chapter5_Loops_And_Files/pg5_3_simple_while_loop.cpp",
          note: "The cleanest place to start loop tracing.",
        },
        {
          name: "pg_5_9_for_loop.cpp",
          path: "../Chapter5_Loops_And_Files/pg_5_9_for_loop.cpp",
          note: "Shows counter-controlled repetition.",
        },
        {
          name: "pg5_14_nested_loops.cpp",
          path: "../Chapter5_Loops_And_Files/pg5_14_nested_loops.cpp",
          note: "A compact example for row/column reasoning.",
        },
        {
          name: "digital_clock.cpp",
          path: "../Chapter5_Loops_And_Files/digital_clock.cpp",
          note: "Good visual example of nested counting logic.",
        },
      ],
      exercises: [
        {
          id: "ch5a-running-total",
          title: "Build a running-total program",
          difficulty: "Easy",
          prompt:
            "Ask the user for numbers until they enter a sentinel value, then print the total and average.",
          hint:
            "Track both `sum` and `count` so the final average is safe.",
        },
        {
          id: "ch5a-pattern-printer",
          title: "Print a loop pattern",
          difficulty: "Medium",
          prompt:
            "Use nested loops to print a right triangle, multiplication table, or simple grid.",
          hint:
            "Trace `pg5_14_nested_loops.cpp` line by line before writing your own pattern.",
        },
        {
          id: "ch5a-menu-repetition",
          title: "Repeat a menu until quit",
          difficulty: "Medium",
          prompt:
            "Wrap a small menu inside a loop so the user can choose actions until they explicitly exit.",
          hint:
            "Study `pg5_8_doWhile_menu.cpp` for the control structure.",
        },
      ],
    },
    {
      id: "ch5b",
      label: "Chapter 5B",
      title: "Basic File I/O Practice",
      folder: "Chapter5_II_Files",
      path: "../Chapter5_II_Files",
      stats: { cpp: 6, headers: 0, data: 4 },
      summary:
        "The repo splits early file work into its own folder, which makes it a good follow-up module after loop basics.",
      whyItMatters:
        "Students often understand loops more deeply once they apply them to reading and writing files.",
      topics: [
        {
          title: "Opening and writing files",
          description:
            "Create output files and verify that the intended data is really being saved.",
        },
        {
          title: "Reading line-oriented data",
          description:
            "Process file input carefully and stop cleanly at the end of the file.",
        },
        {
          title: "Loop-driven file processing",
          description:
            "Combine repetition and file streams to turn one record into many records.",
        },
      ],
      exampleFiles: [
        {
          name: "pg5_15_writing_data_to_file.cpp",
          path: "../Chapter5_II_Files/pg5_15_writing_data_to_file.cpp",
          note: "Minimal write-to-file example.",
        },
        {
          name: "pg5_19_reading_names.cpp",
          path: "../Chapter5_II_Files/pg5_19_reading_names.cpp",
          note: "Simple reading pattern for beginner-friendly text files.",
        },
        {
          name: "pg5_21_writing_data_using_loop.cpp",
          path: "../Chapter5_II_Files/pg5_21_writing_data_using_loop.cpp",
          note: "Connects loops directly to file output.",
        },
        {
          name: "pg5_22_detecting_the_end_of_file.cpp",
          path: "../Chapter5_II_Files/pg5_22_detecting_the_end_of_file.cpp",
          note: "Good place to discuss EOF pitfalls and loop conditions.",
        },
      ],
      exercises: [
        {
          id: "ch5b-name-roster",
          title: "Create a class roster file",
          difficulty: "Easy",
          prompt:
            "Ask for five student names and write them to a text file, one per line.",
          hint:
            "Use the loop-writing example as your skeleton.",
        },
        {
          id: "ch5b-read-and-count",
          title: "Read and count records",
          difficulty: "Medium",
          prompt:
            "Read names or numbers from a file and report how many records were processed.",
          hint:
            "Make the file-processing loop the only place where the count changes.",
        },
        {
          id: "ch5b-copy-filter",
          title: "Filter file contents",
          difficulty: "Medium",
          prompt:
            "Read a source file and copy only the lines or values that match a condition into a second file.",
          hint:
            "Treat each file as one responsibility: one input stream, one output stream.",
        },
      ],
    },
    {
      id: "ch6",
      label: "Chapter 6",
      title: "Functions",
      folder: "Chapter6_Functions",
      path: "../Chapter6_Functions",
      stats: { cpp: 16, headers: 0, data: 1 },
      summary:
        "This chapter breaks programs into reusable functions, covering parameters, return values, references, defaults, and overloads.",
      whyItMatters:
        "Functions are the bridge from small scripts to programs students can actually manage.",
      topics: [
        {
          title: "Value-returning functions",
          description:
            "Use functions to compute and return results rather than keeping all logic in `main`.",
        },
        {
          title: "Argument passing",
          description:
            "Understand pass-by-value, reference variables, and how data moves between caller and callee.",
        },
        {
          title: "Function design tools",
          description:
            "Apply default arguments, overloading, and local-vs-global scope rules responsibly.",
        },
      ],
      exampleFiles: [
        {
          name: "pg6_8_sum_three_numbers.cpp",
          path: "../Chapter6_Functions/pg6_8_sum_three_numbers.cpp",
          note: "Quick entry point for calling a user-defined function.",
        },
        {
          name: "pg6_12_value_returning_function.cpp",
          path: "../Chapter6_Functions/pg6_12_value_returning_function.cpp",
          note: "Separates calculation from display.",
        },
        {
          name: "pg6_25_reference_variables.cpp",
          path: "../Chapter6_Functions/pg6_25_reference_variables.cpp",
          note: "Useful for discussing mutation through references.",
        },
        {
          name: "pg6_27_overloading_functions.cpp",
          path: "../Chapter6_Functions/pg6_27_overloading_functions.cpp",
          note: "Shows one function name serving related jobs.",
        },
      ],
      exercises: [
        {
          id: "ch6-split-a-program",
          title: "Refactor one long program",
          difficulty: "Easy",
          prompt:
            "Take a previous chapter program and divide it into input, processing, and output functions.",
          hint:
            "Only keep orchestration in `main`; move actual work elsewhere.",
        },
        {
          id: "ch6-range-check",
          title: "Write reusable validation functions",
          difficulty: "Medium",
          prompt:
            "Create functions that validate a score, compute a letter grade, and print the result.",
          hint:
            "Each function should do one thing and have a clear name.",
        },
        {
          id: "ch6-overload-lab",
          title: "Overload a utility function",
          difficulty: "Medium",
          prompt:
            "Create overloaded `area` or `maxValue` functions for multiple parameter types or shapes.",
          hint:
            "Use `pg6_27_overloading_functions.cpp` as the structural example.",
        },
      ],
    },
    {
      id: "ch7a",
      label: "Chapter 7A",
      title: "Arrays",
      folder: "Chapter7_Arrays",
      path: "../Chapter7_Arrays",
      stats: { cpp: 26, headers: 0, data: 3 },
      summary:
        "This module covers fixed-size arrays, loops over arrays, file-backed arrays, 2D arrays, and common array algorithms.",
      whyItMatters:
        "Arrays teach students to think about repeated data as a collection instead of many unrelated variables.",
      topics: [
        {
          title: "Initialization and traversal",
          description:
            "Create arrays, access by index, and loop through them safely.",
        },
        {
          title: "Processing collections",
          description:
            "Compute totals, find extremes, compare arrays, and validate input against a list.",
        },
        {
          title: "2D and file-based arrays",
          description:
            "Move from simple one-dimensional arrays into tables and stored datasets.",
        },
      ],
      exampleFiles: [
        {
          name: "pg7_6_array_initialization.cpp",
          path: "../Chapter7_Arrays/pg7_6_array_initialization.cpp",
          note: "Basic fixed-size array setup.",
        },
        {
          name: "pg7_14_readingFile_intoArray.cpp",
          path: "../Chapter7_Arrays/pg7_14_readingFile_intoArray.cpp",
          note: "Good example of arrays plus file input.",
        },
        {
          name: "pg7_21_2D_array.cpp",
          path: "../Chapter7_Arrays/pg7_21_2D_array.cpp",
          note: "Introduces table-like storage and nested loops.",
        },
        {
          name: "pg_7_23_pin_validation.cpp",
          path: "../Chapter7_Arrays/pg_7_23_pin_validation.cpp",
          note: "Practical array comparison and validation example.",
        },
      ],
      exercises: [
        {
          id: "ch7a-score-analyzer",
          title: "Analyze a set of scores",
          difficulty: "Easy",
          prompt:
            "Store ten test scores, then report the highest, lowest, and average.",
          hint:
            "Use one pass if you can: update total, max, and min together.",
        },
        {
          id: "ch7a-pin-checker",
          title: "Build a simple login checker",
          difficulty: "Medium",
          prompt:
            "Compare an entered PIN or passcode against a stored array of digits and print whether it matches.",
          hint:
            "The validation example already gives you the comparison pattern.",
        },
        {
          id: "ch7a-seat-map",
          title: "Create a 2D seating chart",
          difficulty: "Medium",
          prompt:
            "Use a 2D array to store seat availability and allow the user to reserve a seat.",
          hint:
            "Think in terms of row index plus column index, and display the chart after each update.",
        },
      ],
    },
    {
      id: "ch7b",
      label: "Chapter 7B",
      title: "STL Vectors",
      folder: "Chapter7_STL_Vectors",
      path: "../Chapter7_STL_Vectors",
      stats: { cpp: 8, headers: 0, data: 0 },
      summary:
        "This repo separates vectors into their own study module, which is useful because vectors solve many of the sizing issues students run into with raw arrays.",
      whyItMatters:
        "Vectors are the first modern container many students actually enjoy using.",
      topics: [
        {
          title: "Dynamic growth",
          description:
            "Add values with `push_back` instead of committing to a fixed array size at compile time.",
        },
        {
          title: "Container inspection",
          description:
            "Use `size`, emptiness checks, and range-based loops to write safer code.",
        },
        {
          title: "Mutation operations",
          description:
            "Practice clearing, popping, and traversing vectors while keeping indices valid.",
        },
      ],
      exampleFiles: [
        {
          name: "pg_salary_vector_push_back.cpp",
          path: "../Chapter7_STL_Vectors/pg_salary_vector_push_back.cpp",
          note: "Simple growth pattern with `push_back`.",
        },
        {
          name: "pg7_24_salary_vectors.cpp",
          path: "../Chapter7_STL_Vectors/pg7_24_salary_vectors.cpp",
          note: "Useful multi-value vector example.",
        },
        {
          name: "pg7_29_pop_back.cpp",
          path: "../Chapter7_STL_Vectors/pg7_29_pop_back.cpp",
          note: "Shows how to remove from the end safely.",
        },
        {
          name: "pg7_31_detecting_empty_vector.cpp",
          path: "../Chapter7_STL_Vectors/pg7_31_detecting_empty_vector.cpp",
          note: "Good for defensive vector code.",
        },
      ],
      exercises: [
        {
          id: "ch7b-shopping-list",
          title: "Make a vector-based shopping list",
          difficulty: "Easy",
          prompt:
            "Allow the user to add items to a vector and print the full list at the end.",
          hint:
            "Use `push_back` and a range-based loop.",
        },
        {
          id: "ch7b-number-editor",
          title: "Edit a list of numbers",
          difficulty: "Medium",
          prompt:
            "Read numbers into a vector, then let the user remove the last value or clear the whole list.",
          hint:
            "Use `size`, `empty`, `pop_back`, and `clear` together.",
        },
        {
          id: "ch7b-grade-book",
          title: "Track grades in a vector",
          difficulty: "Medium",
          prompt:
            "Store any number of grades, then compute the average only after input is complete.",
          hint:
            "Vectors remove the need to guess how many grades there will be.",
        },
      ],
    },
    {
      id: "ch8",
      label: "Chapter 8",
      title: "Searching and Sorting Arrays",
      folder: "Chapter8_Searching_And_Sorting_Arrays",
      path: "../Chapter8_Searching_And_Sorting_Arrays",
      stats: { cpp: 8, headers: 0, data: 0 },
      summary:
        "Students compare linear vs binary search and work through basic sorting algorithms step by step.",
      whyItMatters:
        "This is where students start thinking about data organization and algorithmic efficiency.",
      topics: [
        {
          title: "Linear and binary search",
          description:
            "Understand when each search method works and what binary search requires from the data first.",
        },
        {
          title: "Elementary sorting algorithms",
          description:
            "Trace bubble, selection, and insertion sort to see exactly how swaps and shifts work.",
        },
        {
          title: "Algorithm comparison",
          description:
            "Talk about tradeoffs in clarity, steps taken, and data preconditions.",
        },
      ],
      exampleFiles: [
        {
          name: "pg8_1_linear_search.cpp",
          path: "../Chapter8_Searching_And_Sorting_Arrays/pg8_1_linear_search.cpp",
          note: "Baseline search on unsorted data.",
        },
        {
          name: "pg8_2_binary_search.cpp",
          path: "../Chapter8_Searching_And_Sorting_Arrays/pg8_2_binary_search.cpp",
          note: "Best file for explaining midpoint logic.",
        },
        {
          name: "bubble_sort.cpp",
          path: "../Chapter8_Searching_And_Sorting_Arrays/bubble_sort.cpp",
          note: "Easy to trace and visualize.",
        },
        {
          name: "selection_sort.cpp",
          path: "../Chapter8_Searching_And_Sorting_Arrays/selection_sort.cpp",
          note: "Good contrast against repeated adjacent swaps.",
        },
        {
          name: "insertion_sort.cpp",
          path: "../Chapter8_Searching_And_Sorting_Arrays/insertion_sort.cpp",
          note: "Useful for showing shifting rather than swapping.",
        },
      ],
      exercises: [
        {
          id: "ch8-search-roster",
          title: "Search a student ID list",
          difficulty: "Easy",
          prompt:
            "Write a linear search that checks whether an entered ID appears in an array.",
          hint:
            "Return the index or `-1` instead of just printing inside the search function.",
        },
        {
          id: "ch8-sort-scores",
          title: "Sort scores from low to high",
          difficulty: "Medium",
          prompt:
            "Implement one of the chapter sort algorithms on an array of scores, then print before and after.",
          hint:
            "Choose one sort first and trace it by hand before coding.",
        },
        {
          id: "ch8-binary-search-lab",
          title: "Combine sort and search",
          difficulty: "Medium",
          prompt:
            "Sort an array, then let the user repeatedly search for values with binary search.",
          hint:
            "Binary search only makes sense after the data is ordered.",
        },
      ],
    },
    {
      id: "ch9",
      label: "Chapter 9",
      title: "Pointers and Dynamic Memory",
      folder: "Chapter9_Pointers",
      path: "../Chapter9_Pointers",
      stats: { cpp: 22, headers: 0, data: 0 },
      summary:
        "This chapter moves from addresses and dereferencing into dynamic allocation, pointer arithmetic, function parameters, and safer ownership with unique pointers.",
      whyItMatters:
        "Pointers are difficult for beginners, so grounding them in concrete files and targeted practice is especially valuable here.",
      topics: [
        {
          title: "Pointer basics",
          description:
            "Connect variables, addresses, dereferencing, and pointer notation without treating them as magic.",
        },
        {
          title: "Pointers in functions and arrays",
          description:
            "See how arrays and pointers interact, especially when data is passed into helper functions.",
        },
        {
          title: "Dynamic memory ownership",
          description:
            "Allocate and release memory safely, then compare raw pointers with `unique_ptr` examples.",
        },
      ],
      exampleFiles: [
        {
          name: "pg9_1_address_of_operator.cpp",
          path: "../Chapter9_Pointers/pg9_1_address_of_operator.cpp",
          note: "Entry point for showing where pointers come from.",
        },
        {
          name: "pg9_9_pointer_arithmetic.cpp",
          path: "../Chapter9_Pointers/pg9_9_pointer_arithmetic.cpp",
          note: "Useful when arrays and pointers start to look equivalent.",
        },
        {
          name: "pg9_14_dynamic_memory_allocation.cpp",
          path: "../Chapter9_Pointers/pg9_14_dynamic_memory_allocation.cpp",
          note: "Introduces heap allocation directly.",
        },
        {
          name: "pg9_17_unique_pointer.cpp",
          path: "../Chapter9_Pointers/pg9_17_unique_pointer.cpp",
          note: "A safer ownership model for modern C++ discussion.",
        },
        {
          name: "swapPtr.cpp",
          path: "../Chapter9_Pointers/swapPtr.cpp",
          note: "Compact example for pointer-based mutation through a function.",
        },
      ],
      exercises: [
        {
          id: "ch9-swap-values",
          title: "Swap two values by address",
          difficulty: "Easy",
          prompt:
            "Write a function that swaps two integers using pointers rather than references.",
          hint:
            "Trace `swapPtr.cpp` and write down what each dereference means.",
        },
        {
          id: "ch9-dynamic-array",
          title: "Allocate a dynamic array",
          difficulty: "Medium",
          prompt:
            "Ask the user how many scores to store, allocate that many values dynamically, and compute the average.",
          hint:
            "Make allocation and deallocation visibly paired in the code.",
        },
        {
          id: "ch9-modern-pointer-compare",
          title: "Rewrite raw ownership with unique_ptr",
          difficulty: "Medium",
          prompt:
            "Take a dynamic-memory example and rewrite it using `unique_ptr` or `unique_ptr<T[]>`.",
          hint:
            "Use the unique-pointer files as the target style to imitate.",
        },
      ],
    },
    {
      id: "ch10",
      label: "Chapter 10",
      title: "Characters, C-Strings, and std::string",
      folder: "Chapter10_Characters, C_Strings, and More About the string Class",
      path: "../Chapter10_Characters, C_Strings, and More About the string Class",
      stats: { cpp: 14, headers: 0, data: 1 },
      summary:
        "Students move from character classification and case conversion into C-string functions and higher-level `string` operations.",
      whyItMatters:
        "Text handling is one of the fastest ways to make console apps feel useful.",
      topics: [
        {
          title: "Character testing and conversion",
          description:
            "Identify digits, letters, and case, then convert text carefully.",
        },
        {
          title: "C-string tools",
          description:
            "Use `strcmp`, `strcpy`, and `strstr` with null-terminated arrays while understanding their limits.",
        },
        {
          title: "Modern string operations",
          description:
            "Compare raw C strings with `std::string` methods for cleaner everyday programming.",
        },
      ],
      exampleFiles: [
        {
          name: "pg10_1_chatacter_testing_functions.cpp",
          path: "../Chapter10_Characters, C_Strings, and More About the string Class/pg10_1_chatacter_testing_functions.cpp",
          note: "Good entry point for character classification functions.",
        },
        {
          name: "pg10_5_c_string.cpp",
          path: "../Chapter10_Characters, C_Strings, and More About the string Class/pg10_5_c_string.cpp",
          note: "Introduces classic C-style string storage.",
        },
        {
          name: "pg10_11_getline.cpp",
          path: "../Chapter10_Characters, C_Strings, and More About the string Class/pg10_11_getline.cpp",
          note: "Useful when comparing C-string input with `std::string` input.",
        },
        {
          name: "pg10_20_stringClass.cpp",
          path: "../Chapter10_Characters, C_Strings, and More About the string Class/pg10_20_stringClass.cpp",
          note: "Bridge into safer and more convenient string handling.",
        },
      ],
      exercises: [
        {
          id: "ch10-password-checker",
          title: "Build a password checker",
          difficulty: "Easy",
          prompt:
            "Read a password and report whether it contains uppercase letters, lowercase letters, and digits.",
          hint:
            "Character-testing functions are enough; no advanced library needed.",
        },
        {
          id: "ch10-word-counter",
          title: "Count characters and words",
          difficulty: "Medium",
          prompt:
            "Read a full line of text and report how many alphabetic characters, digits, spaces, and words it contains.",
          hint:
            "Start with `getline`, then scan one character at a time.",
        },
        {
          id: "ch10-compare-strings",
          title: "Compare C strings and std::string",
          difficulty: "Medium",
          prompt:
            "Write the same text-comparison task twice: once with C strings and once with `std::string`.",
          hint:
            "This is more about understanding tradeoffs than about writing the shortest code.",
        },
      ],
    },
    {
      id: "ch11",
      label: "Chapter 11",
      title: "Structured Data",
      folder: "Chapter11_Structured_Data",
      path: "../Chapter11_Structured_Data",
      stats: { cpp: 7, headers: 0, data: 0 },
      summary:
        "This module introduces `struct`, nested structures, arrays of structures, and enumerated data types.",
      whyItMatters:
        "Structured data lets students model real records instead of scattering related fields across unrelated variables.",
      topics: [
        {
          title: "Basic structures",
          description:
            "Group fields that belong together and access them through one named record.",
        },
        {
          title: "Nested and repeated records",
          description:
            "Combine structures with arrays and nesting to model richer data.",
        },
        {
          title: "Enumerated types",
          description:
            "Represent a closed set of related values with named options instead of raw integers.",
        },
      ],
      exampleFiles: [
        {
          name: "pg11_1_structures.cpp",
          path: "../Chapter11_Structured_Data/pg11_1_structures.cpp",
          note: "Clean starting point for `struct` syntax.",
        },
        {
          name: "pg11_4_structArray.cpp",
          path: "../Chapter11_Structured_Data/pg11_4_structArray.cpp",
          note: "Shows how record collections are stored.",
        },
        {
          name: "pg11_5_nested_struct.cpp",
          path: "../Chapter11_Structured_Data/pg11_5_nested_struct.cpp",
          note: "Useful for modeling real nested information.",
        },
        {
          name: "pg11_11_enumerated_data_type.cpp",
          path: "../Chapter11_Structured_Data/pg11_11_enumerated_data_type.cpp",
          note: "Good for replacing magic numbers with readable labels.",
        },
      ],
      exercises: [
        {
          id: "ch11-student-record",
          title: "Design a student record",
          difficulty: "Easy",
          prompt:
            "Create a `Student` structure with name, ID, and average score, then read and print one record.",
          hint:
            "Keep the structure definition above `main` and make the output clearly labeled.",
        },
        {
          id: "ch11-class-roster",
          title: "Store an array of structures",
          difficulty: "Medium",
          prompt:
            "Create an array of student or employee records and search it for a matching ID.",
          hint:
            "Combine this chapter with Chapter 8 search logic.",
        },
        {
          id: "ch11-enum-menu",
          title: "Use an enum to model state",
          difficulty: "Medium",
          prompt:
            "Define an enum for menu choices, order status, or traffic light state and use it in the control flow.",
          hint:
            "The benefit should be readability, not just syntax practice.",
        },
      ],
    },
    {
      id: "ch12",
      label: "Chapter 12",
      title: "Advanced File Operations",
      folder: "Chapter12_Advanced_File_Operation",
      path: "../Chapter12_Advanced_File_Operation",
      stats: { cpp: 21, headers: 0, data: 11 },
      summary:
        "Chapter 12 expands file handling into formatting, multiple streams, binary files, record storage, and random access.",
      whyItMatters:
        "This is where students start treating files as structured storage instead of just text output.",
      topics: [
        {
          title: "Stream state and formatting",
          description:
            "Control output layout and detect stream errors instead of assuming all I/O succeeds.",
        },
        {
          title: "Binary files and records",
          description:
            "Store raw structured data and learn when binary access is different from text processing.",
        },
        {
          title: "Random access",
          description:
            "Jump to a specific record in a file rather than re-reading the whole file from the start.",
        },
      ],
      exampleFiles: [
        {
          name: "pg12_1_dataFile.cpp",
          path: "../Chapter12_Advanced_File_Operation/pg12_1_dataFile.cpp",
          note: "Good checkpoint before moving into advanced features.",
        },
        {
          name: "pg12_13_binaryFiles.cpp",
          path: "../Chapter12_Advanced_File_Operation/pg12_13_binaryFiles.cpp",
          note: "Introduces binary file writing and reading concepts.",
        },
        {
          name: "pg12_17_randomAccess.cpp",
          path: "../Chapter12_Advanced_File_Operation/pg12_17_randomAccess.cpp",
          note: "Useful for explaining file positions and offsets.",
        },
        {
          name: "pg12_22_edit_inventory.cpp",
          path: "../Chapter12_Advanced_File_Operation/pg12_22_edit_inventory.cpp",
          note: "Strong example of record-based file updates.",
        },
      ],
      exercises: [
        {
          id: "ch12-report-writer",
          title: "Write a formatted report file",
          difficulty: "Easy",
          prompt:
            "Read a few records from the user and save a neatly formatted text report to a file.",
          hint:
            "Use column labels and spacing so the file is human-readable.",
        },
        {
          id: "ch12-binary-inventory",
          title: "Store and read binary inventory records",
          difficulty: "Medium",
          prompt:
            "Design a small record type and write several instances to a binary file, then read them back.",
          hint:
            "Keep the record type simple and fixed-size.",
        },
        {
          id: "ch12-random-update",
          title: "Edit one record in place",
          difficulty: "Hard",
          prompt:
            "Allow the user to update a specific record in a random-access file without rewriting the whole file.",
          hint:
            "Trace the inventory examples and pay attention to file-position functions.",
        },
      ],
    },
    {
      id: "ch13",
      label: "Chapter 13",
      title: "Introduction to Classes",
      folder: "Chapter13_Introduction_to_Classes",
      path: "../Chapter13_Introduction_to_Classes",
      stats: { cpp: 14, headers: 6, data: 0 },
      summary:
        "This chapter moves from structures into classes with private data, methods, constructors, and multi-file object design.",
      whyItMatters:
        "Students start writing their own types instead of just using built-in ones.",
      topics: [
        {
          title: "Class structure",
          description:
            "Separate interface and implementation, and hide internal state behind member functions.",
        },
        {
          title: "Constructors and object lifecycle",
          description:
            "Initialize objects consistently and understand what happens when instances are created.",
        },
        {
          title: "Objects as a design tool",
          description:
            "Package related data and behavior into reusable types such as rectangles, bank accounts, and dice.",
        },
      ],
      exampleFiles: [
        {
          name: "pg13_1_simple_class.cpp",
          path: "../Chapter13_Introduction_to_Classes/pg13_1_simple_class.cpp",
          note: "Smallest entry point into custom classes.",
        },
        {
          name: "pg13_5_rectangle.cpp",
          path: "../Chapter13_Introduction_to_Classes/pg13_5_rectangle.cpp",
          note: "Pairs well with `Rectangle.h` and `Rectangle.cpp`.",
        },
        {
          name: "pg13_7_constructor.cpp",
          path: "../Chapter13_Introduction_to_Classes/pg13_7_constructor.cpp",
          note: "Useful for teaching default initialization and setup.",
        },
        {
          name: "pg13_15_bankAccount.cpp",
          path: "../Chapter13_Introduction_to_Classes/pg13_15_bankAccount.cpp",
          note: "Good real-world class practice with behavior and state.",
        },
      ],
      exercises: [
        {
          id: "ch13-book-class",
          title: "Create a Book class",
          difficulty: "Easy",
          prompt:
            "Design a class with title, author, and page count, then add methods to display and update the record.",
          hint:
            "Start with private fields and simple getters/setters before adding more behavior.",
        },
        {
          id: "ch13-bank-account",
          title: "Extend the bank account",
          difficulty: "Medium",
          prompt:
            "Add deposit, withdraw, and overdraft checks to a simple bank-account class.",
          hint:
            "Use the existing bank-account files as the class layout model.",
        },
        {
          id: "ch13-object-array",
          title: "Store an array of objects",
          difficulty: "Medium",
          prompt:
            "Create several objects of the same class and process them in an array or vector.",
          hint:
            "The array-of-class-objects example is the pattern to imitate.",
        },
      ],
    },
    {
      id: "ch14",
      label: "Chapter 14",
      title: "More About Classes",
      folder: "Chapter14_More_About_Classes",
      path: "../Chapter14_More_About_Classes",
      stats: { cpp: 16, headers: 10, data: 0 },
      summary:
        "This module extends class design with operator overloading, object conversion, aggregation, dynamic arrays, and richer interactions between objects.",
      whyItMatters:
        "Students stop writing only data containers and start making classes feel natural to use.",
      topics: [
        {
          title: "Operator overloading",
          description:
            "Make custom types act more like built-in types when the meaning is clear and consistent.",
        },
        {
          title: "Object relationships",
          description:
            "Model aggregation and multi-class cooperation in a cleaner object-oriented design.",
        },
        {
          title: "Custom containers and conversions",
          description:
            "Work with dynamic arrays and safe conversions between object representations.",
        },
      ],
      exampleFiles: [
        {
          name: "pg14_8_feetInches.cpp",
          path: "../Chapter14_More_About_Classes/pg14_8_feetInches.cpp",
          note: "A strong class for overloading arithmetic and comparisons.",
        },
        {
          name: "pg14_10_comparsion_operator_overloading.cpp",
          path: "../Chapter14_More_About_Classes/pg14_10_comparsion_operator_overloading.cpp",
          note: "Direct comparison-overload practice.",
        },
        {
          name: "pg14_11_stream_operator_overloading.cpp",
          path: "../Chapter14_More_About_Classes/pg14_11_stream_operator_overloading.cpp",
          note: "Great for making custom objects printable.",
        },
        {
          name: "pg14_15_aggregation.cpp",
          path: "../Chapter14_More_About_Classes/pg14_15_aggregation.cpp",
          note: "Shows how objects can contain or reference other objects cleanly.",
        },
      ],
      exercises: [
        {
          id: "ch14-measurement-type",
          title: "Create a measurement class",
          difficulty: "Medium",
          prompt:
            "Build a class like Feet/Inches that supports comparison or addition operators.",
          hint:
            "Keep the class invariant clear before overloading anything.",
        },
        {
          id: "ch14-printable-object",
          title: "Overload stream output",
          difficulty: "Medium",
          prompt:
            "Add `<<` output support to one of your classes so it prints in a clean human-readable form.",
          hint:
            "This is a good place to keep formatting logic out of `main`.",
        },
        {
          id: "ch14-aggregation-model",
          title: "Model related classes",
          difficulty: "Hard",
          prompt:
            "Create two or more classes that work together, such as Course and Instructor or Team and Player.",
          hint:
            "Aggregation is about relationships, not just storing a pointer or value because you can.",
        },
      ],
    },
    {
      id: "ch15",
      label: "Chapter 15",
      title: "Inheritance, Polymorphism, and Virtual Functions",
      folder: "Chapter15_Inheritance_Polymorphism_And_Visual_Functions",
      path: "../Chapter15_Inheritance_Polymorphism_And_Visual_Functions",
      stats: { cpp: 21, headers: 17, data: 0 },
      summary:
        "Students learn inheritance hierarchies, protected members, virtual functions, abstract base classes, override/final, and multiple inheritance.",
      whyItMatters:
        "This chapter is the conceptual shift from isolated classes to families of related types.",
      topics: [
        {
          title: "Base and derived classes",
          description:
            "Reuse state and behavior while deciding what should remain shared and what should change.",
        },
        {
          title: "Runtime polymorphism",
          description:
            "Use base-class pointers and references to call derived behavior through virtual functions.",
        },
        {
          title: "Abstract design",
          description:
            "Model incomplete base types and enforce required behavior with pure virtual functions.",
        },
      ],
      exampleFiles: [
        {
          name: "pg15_1_gradeActivity.cpp",
          path: "../Chapter15_Inheritance_Polymorphism_And_Visual_Functions/pg15_1_gradeActivity.cpp",
          note: "A clear inheritance starting point.",
        },
        {
          name: "pg15_6_car_suv_truck_automobile.cpp",
          path: "../Chapter15_Inheritance_Polymorphism_And_Visual_Functions/pg15_6_car_suv_truck_automobile.cpp",
          note: "Concrete hierarchy students can picture immediately.",
        },
        {
          name: "pg15_11_virtual_memberFunction.cpp",
          path: "../Chapter15_Inheritance_Polymorphism_And_Visual_Functions/pg15_11_virtual_memberFunction.cpp",
          note: "Best file to explain dynamic dispatch.",
        },
        {
          name: "pg15_19_abstractBaseClass_pureVirtualFunction.cpp",
          path: "../Chapter15_Inheritance_Polymorphism_And_Visual_Functions/pg15_19_abstractBaseClass_pureVirtualFunction.cpp",
          note: "Strong example of abstract design rules.",
        },
      ],
      exercises: [
        {
          id: "ch15-shape-hierarchy",
          title: "Build a shape hierarchy",
          difficulty: "Medium",
          prompt:
            "Create a base `Shape` type and derived classes such as `Rectangle` and `Circle` with area methods.",
          hint:
            "Decide early whether area should be virtual or pure virtual.",
        },
        {
          id: "ch15-polymorphic-list",
          title: "Store derived objects behind base pointers",
          difficulty: "Hard",
          prompt:
            "Create several derived objects, store them in one collection of base pointers, and call a virtual method on each.",
          hint:
            "This is where the virtual-function examples matter most.",
        },
        {
          id: "ch15-override-audit",
          title: "Practice override and final",
          difficulty: "Medium",
          prompt:
            "Add `override` in the right places and intentionally test what `final` prevents.",
          hint:
            "Use the override/final example files as your syntax reference.",
        },
      ],
    },
    {
      id: "ch16",
      label: "Chapter 16",
      title: "Exceptions, Templates, and the STL",
      folder: "Chapter16_Exception_Templates_and_the_Standard_Template_Library(STL)",
      path: "../Chapter16_Exception_Templates_and_the_Standard_Template_Library(STL)",
      stats: { cpp: 19, headers: 5, data: 0 },
      summary:
        "This chapter ties together exception handling, function/class templates, iterators, STL containers, and standard algorithms.",
      whyItMatters:
        "It gives students a more modern C++ toolset and shows how the standard library removes a lot of manual work.",
      topics: [
        {
          title: "Exceptions",
          description:
            "Separate normal program flow from error recovery and guard unsafe operations.",
        },
        {
          title: "Templates",
          description:
            "Write reusable logic that works across multiple types without copy-pasting code.",
        },
        {
          title: "STL algorithms and containers",
          description:
            "Use vectors, iterators, and algorithms like `find`, `sort`, `max_element`, and `for_each`.",
        },
      ],
      exampleFiles: [
        {
          name: "pg16_1_division_by_zero.cpp",
          path: "../Chapter16_Exception_Templates_and_the_Standard_Template_Library(STL)/pg16_1_division_by_zero.cpp",
          note: "Simple entry point into exception handling.",
        },
        {
          name: "pg16_7_templates.cpp",
          path: "../Chapter16_Exception_Templates_and_the_Standard_Template_Library(STL)/pg16_7_templates.cpp",
          note: "Straightforward function-template example.",
        },
        {
          name: "pg16_11_simple_vector.cpp",
          path: "../Chapter16_Exception_Templates_and_the_Standard_Template_Library(STL)/pg16_11_simple_vector.cpp",
          note: "Useful when comparing custom containers with STL ones.",
        },
        {
          name: "pg16_15_random_shuffle_sort_binary_search.cpp",
          path: "../Chapter16_Exception_Templates_and_the_Standard_Template_Library(STL)/pg16_15_random_shuffle_sort_binary_search.cpp",
          note: "Strong algorithm-composition example.",
        },
      ],
      exercises: [
        {
          id: "ch16-safe-divider",
          title: "Protect a risky operation",
          difficulty: "Easy",
          prompt:
            "Write a division program that throws or handles an error for division by zero.",
          hint:
            "Focus on clear error flow rather than clever syntax.",
        },
        {
          id: "ch16-template-utility",
          title: "Create a reusable template",
          difficulty: "Medium",
          prompt:
            "Write a generic `swapValues`, `maxValue`, or `clampValue` function template and test it with multiple types.",
          hint:
            "Use at least one numeric type and one different numeric type to prove the template works.",
        },
        {
          id: "ch16-stl-practice",
          title: "Solve a problem with STL algorithms",
          difficulty: "Medium",
          prompt:
            "Store values in a vector, sort them, search them, and compute the max or min using standard algorithms instead of manual loops.",
          hint:
            "The point is to replace boilerplate, not to write the longest answer.",
        },
      ],
    },
  ],
  supplemental: [
    {
      id: "programming-challenges",
      label: "Programming Challenges",
      title: "Programming Challenges Folder",
      path: "../Programming Challenges",
      stats: { cpp: 43, headers: 4, data: 1 },
      summary:
        "This is the strongest practice bank in the repo because the filenames already line up with textbook chapter numbers.",
      recommendation:
        "Use these after students finish the guided exercises in each chapter. They are better suited for homework, quizzes, and self-checks than for first exposure.",
      bestFor: [
        "Extra drills after Chapters 5 to 9 and Chapter 13",
        "Challenge problems that go beyond the smallest book demos",
        "Creating weekly practice sets without inventing new prompts from scratch",
      ],
      exampleFiles: [
        {
          name: "5_10_average_rainfall.cpp",
          path: "../Programming Challenges/5_10_average_rainfall.cpp",
          note: "Loop and accumulator practice.",
        },
        {
          name: "7_8_lo_shu_magic_square.cpp",
          path: "../Programming Challenges/7_8_lo_shu_magic_square.cpp",
          note: "A richer array problem with real checking logic.",
        },
        {
          name: "9_11_array_expander.cpp",
          path: "../Programming Challenges/9_11_array_expander.cpp",
          note: "Good follow-up practice for dynamic memory topics.",
        },
        {
          name: "13_3_car.cpp",
          path: "../Programming Challenges/13_3_car.cpp",
          note: "Class design practice after the main chapter examples.",
        },
      ],
    },
    {
      id: "csc111-profyan",
      label: "CSC111 Material",
      title: "CSC111 Professor Yan Material",
      path: "../CSC111_ProfYan",
      stats: { cpp: 78, headers: 2, data: 5 },
      summary:
        "This folder is a reinforcement library for beginners. It contains many short classworks that overlap with the early textbook chapters.",
      recommendation:
        "Use it for warm-ups, live-lab exercises, and review weeks when students need extra repetition on fundamentals.",
      bestFor: [
        "Conditionals, loops, functions, arrays, and recursion refreshers",
        "Short in-class practice before assigning textbook problems",
        "Alternative examples when one textbook file is too abstract for a student",
      ],
      breakdown: [
        "CSC111_HomeWorks: 8 .cpp",
        "RECURSIVES: 1 .cpp",
        "dec 02|04|09_classworks: 11 .cpp, 2 headers",
        "nov11|13_classwork_arrays: 2 .cpp, 1 data file",
        "nov18|20|25_classwork: 4 .cpp",
        "sep11_classwork through oct28: multiple short labs across the semester",
      ],
      exampleFiles: [
        {
          name: "sep18_classwork/simple_integer_calculator_switch.cpp",
          path: "../CSC111_ProfYan/sep18_classwork/simple_integer_calculator_switch.cpp",
          note: "Good conditional and switch review material.",
        },
        {
          name: "nov11|13_classwork_arrays/arrays.cpp",
          path: "../CSC111_ProfYan/nov11|13_classwork_arrays/arrays.cpp",
          note: "Beginner-friendly array practice.",
        },
        {
          name: "oct28/29_classwork/value_return_function.cpp",
          path: "../CSC111_ProfYan/oct28/29_classwork/value_return_function.cpp",
          note: "Useful for Chapter 6 reinforcement.",
        },
        {
          name: "RECURSIVES/isEqual.cpp",
          path: "../CSC111_ProfYan/RECURSIVES/isEqual.cpp",
          note: "Small recursion example for later review.",
        },
      ],
    },
    {
      id: "csc211-azhhar",
      label: "CSC211H Material",
      title: "CSC211H Professor Azhar Material",
      path: "../CSC211H_Prof_Azhar",
      stats: { cpp: 53, headers: 16, data: 5 },
      summary:
        "This part of the repo contains larger assignments, exam questions, zyBook-style practice, and multi-file projects.",
      recommendation:
        "Treat this as the project and assessment layer of the app. It is best used after students already know the chapter concepts.",
      bestFor: [
        "Capstone-style assignments that combine several chapters",
        "Exam review and structured practice problems",
        "Object-oriented and file I/O project work",
      ],
      breakdown: [
        "Assignment1_Roomba: 5 .cpp, 1 header, 1 data file",
        "Assignment2_RoboTreasure: 10 .cpp, 4 headers",
        "Assignment3_FileIO: 7 .cpp, 4 headers, 4 data files",
        "ClassWorks: 17 .cpp, 7 headers",
        "ExamQuestions: 4 .cpp",
        "zybook: 9 .cpp",
      ],
      exampleFiles: [
        {
          name: "Assignment2_RoboTreasure/robotGame.cpp",
          path: "../CSC211H_Prof_Azhar/Assignment2_RoboTreasure/robotGame.cpp",
          note: "A larger multi-file project for project-based practice.",
        },
        {
          name: "Assignment3_FileIO/Part1/filecmd.cpp",
          path: "../CSC211H_Prof_Azhar/Assignment3_FileIO/Part1/filecmd.cpp",
          note: "Useful for file-processing lessons and project work.",
        },
        {
          name: "ExamQuestions/4_emp_class.cpp",
          path: "../CSC211H_Prof_Azhar/ExamQuestions/4_emp_class.cpp",
          note: "Good short review problem for classes.",
        },
        {
          name: "zybook/Vector/grocery_shopping.cpp",
          path: "../CSC211H_Prof_Azhar/zybook/Vector/grocery_shopping.cpp",
          note: "Supplemental vector practice from a different source.",
        },
      ],
    },
  ],
};
