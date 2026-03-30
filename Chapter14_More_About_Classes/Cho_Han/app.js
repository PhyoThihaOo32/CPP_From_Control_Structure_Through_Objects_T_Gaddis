const TOTAL_ROUNDS = 5;

const SONGS = {
  matsuri: {
    taikoTempo: 360,
    melodyTempo: 760,
    kotoTempo: 520,
    melody: [392.0, 440.0, 523.25, 440.0, 392.0, 349.23, 329.63, 349.23],
    bass: [92, 86, 92, 78],
    volume: 0.18
  },
  kaidan: {
    taikoTempo: 430,
    melodyTempo: 920,
    kotoTempo: 650,
    melody: [261.63, 293.66, 329.63, 293.66, 246.94, 220.0, 196.0, 220.0],
    bass: [82, 73, 82, 69],
    volume: 0.16
  },
  sakura: {
    taikoTempo: 390,
    melodyTempo: 700,
    kotoTempo: 480,
    melody: [293.66, 329.63, 392.0, 440.0, 493.88, 440.0, 392.0, 329.63],
    bass: [98, 92, 88, 92],
    volume: 0.17
  },
  oni: {
    taikoTempo: 300,
    melodyTempo: 640,
    kotoTempo: 430,
    melody: [349.23, 392.0, 466.16, 392.0, 349.23, 311.13, 293.66, 311.13],
    bass: [104, 98, 92, 86],
    volume: 0.2
  },
  gagaku: {
    taikoTempo: 520,
    melodyTempo: 1100,
    kotoTempo: 730,
    melody: [220.0, 246.94, 261.63, 293.66, 329.63, 293.66, 261.63, 246.94],
    bass: [73, 69, 65, 62],
    volume: 0.15
  },
  bon: {
    taikoTempo: 340,
    melodyTempo: 680,
    kotoTempo: 460,
    melody: [329.63, 392.0, 440.0, 392.0, 329.63, 293.66, 261.63, 293.66],
    bass: [98, 92, 86, 82],
    volume: 0.19
  }
};

const MUSIC_TRACKS = {
  local_bounce: {
    title: "Traditional Japanese 3",
    streamUrl: "./bounce-bay-records-traditional-japanese-3-437933.mp3",
    fallbackSong: "sakura"
  },
  local_senso: {
    title: "Senso Trap Japanese Warrior",
    streamUrl: "./onesevenbeatxs-senso-trap-japanese-warrior-rap-beat-prod-by-onesevenbeatxs-328644.mp3",
    fallbackSong: "oni"
  }
};

const BASE_PATTERN = [
  "................",
  ".....OOOOOO.....",
  "....OBBBBBBO....",
  "...OBBBBBBBBO...",
  "...OBBBBBBBBO...",
  "...OBBEEEBBBO...",
  "...OBBBBBBBBO...",
  "...OBBBAABBBO...",
  "...OBBBBBBBBO...",
  "...OBBBBBBBBO...",
  "...OBBBBBBBBO...",
  "...OBBBBBBBBO...",
  "...OBB.BB.BBO...",
  "...OB..BB..BO...",
  "....OOOOOOOO....",
  "................"
];

const BOSS_PATTERN = [
  "................",
  "....OOOOOOOO....",
  "...OBBBBBBBBO...",
  "..OBBBBBBBBBBO..",
  "..OBBBBBBBBBBO..",
  "..OBBSSSSSSBBO..",
  "..OBBEEEEEEBBO..",
  "..OBBBBBBBBBBO..",
  "..OBBBBAABBBBO..",
  "..OBBBBBBBBBBO..",
  "..OBBBBBBBBBBO..",
  "..OBBBBBBBBBBO..",
  "..OBBB.BBBB.BO..",
  "...OB..BB..BO...",
  "....OOOOOOOO....",
  "................"
];

const SPRITE_BLUEPRINTS = [
  {
    id: "kage_yurei",
    label: "Kage Yurei",
    palette: { O: "#161628", B: "#80c5ff", E: "#ff4f6b", A: "#d8f4ff" }
  },
  {
    id: "hana_rei",
    label: "Hana Rei",
    palette: { O: "#27152b", B: "#d9a5ff", E: "#ff4fa3", A: "#ffd8f6", P: "#ffe57f" },
    pixels: [
      { x: 5, y: 1, key: "P" },
      { x: 6, y: 1, key: "P" },
      { x: 5, y: 2, key: "P" },
      { x: 6, y: 2, key: "P" }
    ]
  },
  {
    id: "sumi_monk",
    label: "Sumi Monk",
    palette: { O: "#101520", B: "#7a86ab", E: "#ffc96e", A: "#b7c4ee", H: "#2f374b" },
    rects: [{ x: 4, y: 2, w: 8, h: 3, key: "H" }]
  },
  {
    id: "kitsune_mask",
    label: "Kitsune Mask",
    palette: { O: "#21181a", B: "#f0f0ff", E: "#ff3b3b", A: "#ffe7be", R: "#ff8b8b" },
    pixels: [
      { x: 6, y: 5, key: "R" },
      { x: 9, y: 5, key: "R" },
      { x: 7, y: 7, key: "R" },
      { x: 8, y: 7, key: "R" }
    ]
  },
  {
    id: "tengu_ember",
    label: "Tengu Ember",
    palette: { O: "#1e1820", B: "#8790f9", E: "#94ff73", A: "#ff8e8e", N: "#ff5a4d" },
    pixels: [{ x: 8, y: 6, key: "N" }, { x: 8, y: 7, key: "N" }]
  },
  {
    id: "bonfire_blob",
    label: "Bonfire Blob",
    palette: { O: "#261315", B: "#ff8080", E: "#fff05d", A: "#ffc9a0" }
  },
  {
    id: "oyabun_fat",
    label: "Oyabun Boss",
    pattern: BOSS_PATTERN,
    palette: { O: "#0d1016", B: "#586587", E: "#ff2f45", A: "#9ad0ff", S: "#020205" },
    rects: [{ x: 5, y: 9, w: 6, h: 2, key: "A" }]
  },
  {
    id: "tsuki_mist",
    label: "Tsuki Mist",
    palette: { O: "#172128", B: "#b0f5ff", E: "#ff5f6f", A: "#e6ffff" }
  }
];

function makeSpriteImage(blueprint) {
  const pattern = blueprint.pattern || BASE_PATTERN;
  const height = pattern.length;
  const width = pattern.reduce((max, row) => Math.max(max, row.length), 0);

  const canvas = document.createElement("canvas");
  canvas.width = width;
  canvas.height = height;

  const ctx = canvas.getContext("2d", { alpha: true });

  pattern.forEach((row, y) => {
    for (let x = 0; x < width; x += 1) {
      const key = row[x] || ".";
      const color = blueprint.palette[key];
      if (!color) {
        continue;
      }

      ctx.fillStyle = color;
      ctx.fillRect(x, y, 1, 1);
    }
  });

  (blueprint.rects || []).forEach(({ x, y, w, h, key }) => {
    const color = blueprint.palette[key];
    if (!color) {
      return;
    }

    ctx.fillStyle = color;
    ctx.fillRect(x, y, w, h);
  });

  (blueprint.pixels || []).forEach(({ x, y, key }) => {
    const color = blueprint.palette[key];
    if (!color) {
      return;
    }

    ctx.fillStyle = color;
    ctx.fillRect(x, y, 1, 1);
  });

  return canvas.toDataURL("image/png");
}

const SPRITES = SPRITE_BLUEPRINTS.map((blueprint) => {
  const pattern = blueprint.pattern || BASE_PATTERN;
  return {
    id: blueprint.id,
    label: blueprint.label,
    image: makeSpriteImage(blueprint),
    w: pattern[0].length,
    h: pattern.length
  };
});

const DEALER_POOL_IDS = ["oyabun_fat", "sumi_monk", "tengu_ember", "kage_yurei"];

const state = {
  round: 1,
  gameOver: false,
  rolling: false,
  characters: {
    human: SPRITES[0].id,
    aiko: SPRITES[1].id,
    dealer: "oyabun_fat"
  },
  players: {
    human: { name: "You", score: 0, guess: null },
    aiko: { name: "Computer", score: 0, guess: null }
  }
};

const ui = {
  roundDisplay: document.getElementById("roundDisplay"),
  dealerLine: document.getElementById("dealerLine"),
  dieOne: document.getElementById("dieOne"),
  dieTwo: document.getElementById("dieTwo"),
  resultPill: document.getElementById("resultPill"),
  scoreHuman: document.getElementById("scoreHuman"),
  scoreAiko: document.getElementById("scoreAiko"),
  scoreLabelCpu: document.getElementById("scoreLabelCpu"),
  guessHuman: document.getElementById("guessHuman"),
  guessAiko: document.getElementById("guessAiko"),
  speechDealer: document.getElementById("speechDealer"),
  speechPlayer: document.getElementById("speechPlayer"),
  speechAiko: document.getElementById("speechAiko"),
  dealerChar: document.getElementById("dealerChar"),
  playerChar: document.getElementById("playerChar"),
  aikoChar: document.getElementById("aikoChar"),
  dealerSprite: document.getElementById("dealerSprite"),
  playerSprite: document.getElementById("playerSprite"),
  aikoSprite: document.getElementById("aikoSprite"),
  dealerNameTag: document.getElementById("dealerNameTag"),
  playerNameTag: document.getElementById("playerNameTag"),
  aikoNameTag: document.getElementById("aikoNameTag"),
  playerSpriteSelect: document.getElementById("playerSpriteSelect"),
  betCho: document.getElementById("betCho"),
  betHan: document.getElementById("betHan"),
  songSelect: document.getElementById("songSelect"),
  musicToggle: document.getElementById("musicToggle"),
  restartBtn: document.getElementById("restartBtn"),
  resultOverlay: document.getElementById("resultOverlay"),
  winnerText: document.getElementById("winnerText")
};

const DICE_SYMBOLS = ["", "⚀", "⚁", "⚂", "⚃", "⚄", "⚅"];

function randomDie() {
  return Math.floor(Math.random() * 6) + 1;
}

function randomGuess() {
  return Math.random() < 0.5 ? "Cho" : "Han";
}

function resultFromSum(sum) {
  return sum % 2 === 0 ? "Cho" : "Han";
}

function guessLabel(guess) {
  if (!guess) {
    return "-";
  }

  return guess === "Cho" ? "Cho (Even)" : "Han (Odd)";
}

function getSpriteById(id) {
  return SPRITES.find((sprite) => sprite.id === id) || SPRITES[0];
}

function pickRandomSpriteId(excludedIds = new Set(), poolIds = SPRITES.map((sprite) => sprite.id)) {
  const candidates = poolIds.filter((id) => !excludedIds.has(id));
  const source = candidates.length > 0 ? candidates : poolIds;
  return source[Math.floor(Math.random() * source.length)];
}

function calcSpriteScale(frameWidth, frameHeight) {
  const basePixels = 96;
  const fitted = Math.min((frameWidth - 18) / basePixels, (frameHeight - 18) / basePixels);
  return Math.max(1.2, Math.min(2.15, fitted));
}

function renderSprite(node, sprite, frameWidth, frameHeight, boost = 1) {
  const scale = (calcSpriteScale(frameWidth, frameHeight) * boost).toFixed(2);

  node.style.width = "96px";
  node.style.height = "96px";
  node.style.backgroundImage = `url("${sprite.image}")`;
  node.style.backgroundSize = "100% 100%";
  node.style.backgroundPosition = "center";
  node.style.setProperty("--sprite-scale", scale);
  node.setAttribute("title", sprite.label);
}

function applyRosterToUi() {
  const humanSprite = getSpriteById(state.characters.human);
  const cpuSprite = getSpriteById(state.characters.aiko);
  const dealerSprite = getSpriteById(state.characters.dealer);

  renderSprite(ui.playerSprite, humanSprite, 172, 172);
  renderSprite(ui.aikoSprite, cpuSprite, 172, 172);
  renderSprite(ui.dealerSprite, dealerSprite, 194, 188, 1.08);

  ui.playerNameTag.textContent = `You • ${humanSprite.label}`;
  ui.aikoNameTag.textContent = cpuSprite.label;
  ui.dealerNameTag.textContent = `Oyabun Dealer • ${dealerSprite.label}`;
  ui.scoreLabelCpu.textContent = cpuSprite.label;

  state.players.aiko.name = cpuSprite.label;
}

function assignRandomOpponents() {
  const excluded = new Set([state.characters.human]);
  state.characters.dealer = pickRandomSpriteId(excluded, DEALER_POOL_IDS);
  excluded.add(state.characters.dealer);
  state.characters.aiko = pickRandomSpriteId(excluded);
}

function buildCharacterPicker() {
  ui.playerSpriteSelect.innerHTML = "";

  SPRITES.forEach((sprite) => {
    const option = document.createElement("option");
    option.value = sprite.id;
    option.textContent = sprite.label;
    ui.playerSpriteSelect.appendChild(option);
  });

  ui.playerSpriteSelect.value = state.characters.human;
}

function handlePlayerCharacterChange() {
  state.characters.human = ui.playerSpriteSelect.value;

  if (state.characters.aiko === state.characters.human || state.characters.dealer === state.characters.human) {
    assignRandomOpponents();
  }

  applyRosterToUi();
  setSpeech(ui.speechPlayer, `${getSpriteById(state.characters.human).label}`);
}

function setSpeech(node, text) {
  node.textContent = text;
  node.classList.remove("pop");
  void node.offsetWidth;
  node.classList.add("pop");
}

function clearRoundClasses() {
  [ui.playerChar, ui.aikoChar].forEach((node) => {
    node.classList.remove("win", "lose");
  });
}

function setControlsDisabled(disabled) {
  ui.betCho.disabled = disabled;
  ui.betHan.disabled = disabled;
}

function setRollingState(isRolling) {
  state.rolling = isRolling;
  ui.dealerChar.classList.toggle("rolling", isRolling);
  ui.dieOne.classList.toggle("rolling", isRolling);
  ui.dieTwo.classList.toggle("rolling", isRolling);

  if (isRolling) {
    setControlsDisabled(true);
  } else if (!state.gameOver) {
    setControlsDisabled(false);
  }
}

function updateHud() {
  ui.roundDisplay.textContent = `Round ${Math.min(state.round, TOTAL_ROUNDS)} / ${TOTAL_ROUNDS}`;
  ui.scoreHuman.textContent = String(state.players.human.score);
  ui.scoreAiko.textContent = String(state.players.aiko.score);
  ui.guessHuman.textContent = guessLabel(state.players.human.guess);
  ui.guessAiko.textContent = guessLabel(state.players.aiko.guess);
}

function markWinners(result) {
  ["human", "aiko"].forEach((id) => {
    const node = id === "human" ? ui.playerChar : ui.aikoChar;
    if (state.players[id].guess === result) {
      state.players[id].score += 1;
      node.classList.add("win");
    } else {
      node.classList.add("lose");
    }
  });
}

function startDiceShuffle(durationMs, onDone) {
  setRollingState(true);

  const interval = window.setInterval(() => {
    ui.dieOne.textContent = DICE_SYMBOLS[randomDie()];
    ui.dieTwo.textContent = DICE_SYMBOLS[randomDie()];
  }, 90);

  window.setTimeout(() => {
    clearInterval(interval);
    setRollingState(false);
    onDone();
  }, durationMs);
}

function finishMatch() {
  state.gameOver = true;
  setControlsDisabled(true);
  ui.resultOverlay.classList.remove("hidden");

  if (state.players.human.score > state.players.aiko.score) {
    ui.winnerText.textContent = `You Win ${state.players.human.score} - ${state.players.aiko.score}`;
    ui.dealerLine.textContent = "Match over. You take the spirit pot. Press Restart Match for a new game.";
    setSpeech(ui.speechDealer, "Oyabun bows to you");
  } else if (state.players.aiko.score > state.players.human.score) {
    ui.winnerText.textContent = `${state.players.aiko.name} Wins ${state.players.aiko.score} - ${state.players.human.score}`;
    ui.dealerLine.textContent = `Match over. ${state.players.aiko.name} takes the spirit pot. Press Restart Match for a new game.`;
    setSpeech(ui.speechDealer, `${state.players.aiko.name} claims it`);
  } else {
    ui.winnerText.textContent = `Tie ${state.players.human.score} - ${state.players.aiko.score}`;
    ui.dealerLine.textContent = "Match over with equal fate. Press Restart Match for a new game.";
    setSpeech(ui.speechDealer, "Balanced under moonlight");
  }
}

function playRound(humanGuess) {
  if (state.gameOver || state.rolling) {
    return;
  }

  clearRoundClasses();
  ui.resultOverlay.classList.add("hidden");

  state.players.human.guess = humanGuess;
  state.players.aiko.guess = randomGuess();

  setSpeech(ui.speechPlayer, guessLabel(state.players.human.guess));
  setSpeech(ui.speechAiko, `${state.players.aiko.name}: ${guessLabel(state.players.aiko.guess)}`);
  setSpeech(ui.speechDealer, "Oyabun shakes the cup");

  ui.dealerLine.textContent = "Dealer shakes the ghost cup...";
  ui.resultPill.textContent = "Rolling";

  audio.playTaikoFill();

  startDiceShuffle(1300, () => {
    const die1 = randomDie();
    const die2 = randomDie();
    const sum = die1 + die2;
    const result = resultFromSum(sum);

    ui.dieOne.textContent = DICE_SYMBOLS[die1];
    ui.dieTwo.textContent = DICE_SYMBOLS[die2];
    ui.resultPill.textContent = guessLabel(result);

    markWinners(result);

    const playerWon = state.players.human.guess === result;
    const cpuWon = state.players.aiko.guess === result;

    setSpeech(ui.speechDealer, `${guessLabel(result)}`);
    setSpeech(ui.speechPlayer, playerWon ? "Yatta" : "Next hand");
    setSpeech(ui.speechAiko, cpuWon ? "Spirit smiles" : "Shadow fades");

    ui.dealerLine.textContent = `Dealer rolled ${die1} + ${die2} = ${sum}. Result: ${guessLabel(result)}.`;

    audio.playRollAccent();
    updateHud();

    if (state.round >= TOTAL_ROUNDS) {
      finishMatch();
      return;
    }

    state.round += 1;
    updateHud();
  });
}

function resetGame() {
  state.round = 1;
  state.gameOver = false;
  state.rolling = false;

  state.players.human.score = 0;
  state.players.aiko.score = 0;
  state.players.human.guess = null;
  state.players.aiko.guess = null;

  assignRandomOpponents();
  applyRosterToUi();

  clearRoundClasses();
  ui.resultOverlay.classList.add("hidden");

  ui.dieOne.textContent = DICE_SYMBOLS[1];
  ui.dieTwo.textContent = DICE_SYMBOLS[1];
  ui.resultPill.textContent = "Waiting";

  setSpeech(ui.speechDealer, "Oyabun opens the table");
  setSpeech(ui.speechPlayer, "Choose Cho or Han");
  setSpeech(ui.speechAiko, `${state.players.aiko.name} appears`);

  ui.dealerLine.textContent = "Make your guess. Dealer will roll.";
  setControlsDisabled(false);
  updateHud();
}

class MultiSongAudio {
  constructor(onExternalFail) {
    this.ctx = null;
    this.master = null;
    this.isOn = false;
    this.songKey = "local_bounce";
    this.synthKey = MUSIC_TRACKS[this.songKey].fallbackSong;
    this.loopTimers = [];
    this.beatStep = 0;
    this.melodyStep = 0;
    this.onExternalFail = onExternalFail;
    this.externalAudio = new Audio();
    this.externalAudio.loop = true;
    this.externalAudio.preload = "none";
    this.externalAudio.volume = 0.62;
    this.usingExternal = false;
  }

  ensureCtx() {
    if (!this.ctx) {
      this.ctx = new (window.AudioContext || window.webkitAudioContext)();
      this.master = this.ctx.createGain();
      this.master.gain.value = 0.18;
      this.master.connect(this.ctx.destination);
    }

    if (this.ctx.state === "suspended") {
      void this.ctx.resume();
    }
  }

  getSynthConfig() {
    return SONGS[this.synthKey] || SONGS.matsuri;
  }

  hasTrack(songKey) {
    return Boolean(MUSIC_TRACKS[songKey]);
  }

  setSong(songKey) {
    if (!SONGS[songKey] && !MUSIC_TRACKS[songKey]) {
      return;
    }

    this.songKey = songKey;
    this.synthKey = this.hasTrack(songKey)
      ? MUSIC_TRACKS[songKey].fallbackSong
      : songKey;

    if (!this.isOn) {
      return;
    }

    this.stopSynthLoops();
    this.externalAudio.pause();
    this.externalAudio.currentTime = 0;
    this.usingExternal = false;

    if (this.hasTrack(this.songKey)) {
      this.startExternalTrack();
      return;
    }

    this.startSynthLoops();
  }

  tone(freq, duration, type = "sine", volume = 0.2, attack = 0.01) {
    const osc = this.ctx.createOscillator();
    const gain = this.ctx.createGain();

    osc.type = type;
    osc.frequency.setValueAtTime(freq, this.ctx.currentTime);

    gain.gain.setValueAtTime(0.0001, this.ctx.currentTime);
    gain.gain.exponentialRampToValueAtTime(volume, this.ctx.currentTime + attack);
    gain.gain.exponentialRampToValueAtTime(0.0001, this.ctx.currentTime + duration);

    osc.connect(gain);
    gain.connect(this.master);

    osc.start();
    osc.stop(this.ctx.currentTime + duration + 0.05);
  }

  playTaiko(strong = false) {
    const config = this.getSynthConfig();
    const bassFreq = config.bass[this.beatStep % config.bass.length];
    const volume = strong ? config.volume * 3.2 : config.volume * 2.2;

    this.tone(bassFreq, strong ? 0.3 : 0.18, "sine", volume, 0.003);
    setTimeout(() => this.tone(bassFreq * 0.5, 0.12, "triangle", config.volume * 0.9, 0.002), 24);
  }

  playKoto(freq) {
    const config = this.getSynthConfig();
    this.tone(freq, 0.2, "triangle", config.volume * 1.05, 0.005);
    setTimeout(() => this.tone(freq * 2, 0.11, "triangle", config.volume * 0.45, 0.003), 18);
  }

  playShakuhachi(freq) {
    const config = this.getSynthConfig();

    const osc = this.ctx.createOscillator();
    const gain = this.ctx.createGain();
    const lfo = this.ctx.createOscillator();
    const lfoGain = this.ctx.createGain();
    const filter = this.ctx.createBiquadFilter();

    osc.type = "sawtooth";
    osc.frequency.setValueAtTime(freq, this.ctx.currentTime);

    filter.type = "lowpass";
    filter.frequency.setValueAtTime(1100, this.ctx.currentTime);
    filter.Q.value = 4;

    lfo.type = "sine";
    lfo.frequency.setValueAtTime(5, this.ctx.currentTime);
    lfoGain.gain.setValueAtTime(7, this.ctx.currentTime);
    lfo.connect(lfoGain);
    lfoGain.connect(osc.frequency);

    gain.gain.setValueAtTime(0.0001, this.ctx.currentTime);
    gain.gain.exponentialRampToValueAtTime(config.volume * 0.85, this.ctx.currentTime + 0.04);
    gain.gain.exponentialRampToValueAtTime(0.0001, this.ctx.currentTime + 0.55);

    osc.connect(filter);
    filter.connect(gain);
    gain.connect(this.master);

    lfo.start();
    osc.start();
    osc.stop(this.ctx.currentTime + 0.6);
    lfo.stop(this.ctx.currentTime + 0.6);
  }

  stopSynthLoops() {
    this.loopTimers.forEach((timer) => clearInterval(timer));
    this.loopTimers = [];
  }

  startSynthLoops() {
    this.stopSynthLoops();
    this.beatStep = 0;
    this.melodyStep = 0;

    const config = this.getSynthConfig();

    this.loopTimers.push(
      window.setInterval(() => {
        const strong = this.beatStep % 4 === 0;
        const offbeat = this.beatStep % 4 === 2;

        if (strong || offbeat) {
          this.playTaiko(strong);
        }

        this.beatStep += 1;
      }, config.taikoTempo)
    );

    this.loopTimers.push(
      window.setInterval(() => {
        const note = config.melody[this.melodyStep % config.melody.length];
        this.playShakuhachi(note);
        this.melodyStep += 1;
      }, config.melodyTempo)
    );

    this.loopTimers.push(
      window.setInterval(() => {
        const note = config.melody[this.melodyStep % config.melody.length] * 0.5;
        this.playKoto(note);
      }, config.kotoTempo)
    );
  }

  startExternalTrack() {
    const selectedTrackKey = this.songKey;
    const track = MUSIC_TRACKS[selectedTrackKey];

    this.externalAudio.pause();
    this.externalAudio.src = track.streamUrl;
    this.externalAudio.currentTime = 0;

    const playPromise = this.externalAudio.play();
    if (!playPromise || typeof playPromise.then !== "function") {
      this.usingExternal = true;
      return;
    }

    void playPromise
      .then(() => {
        if (!this.isOn || this.songKey !== selectedTrackKey) {
          this.externalAudio.pause();
          return;
        }
        this.usingExternal = true;
      })
      .catch(() => {
        if (!this.isOn || this.songKey !== selectedTrackKey) {
          return;
        }
        this.usingExternal = false;
        this.startSynthLoops();
        if (typeof this.onExternalFail === "function") {
          this.onExternalFail("Selected track could not stream directly. Using built-in fallback.");
        }
      });
  }

  start() {
    this.ensureCtx();
    if (this.isOn) {
      return;
    }

    this.isOn = true;
    this.stopSynthLoops();
    this.externalAudio.pause();
    this.externalAudio.currentTime = 0;
    this.usingExternal = false;

    if (this.hasTrack(this.songKey)) {
      this.startExternalTrack();
      return;
    }

    this.startSynthLoops();
  }

  stop() {
    this.isOn = false;
    this.stopSynthLoops();
    this.externalAudio.pause();
    this.externalAudio.currentTime = 0;
    this.usingExternal = false;
  }

  toggle() {
    if (this.isOn) {
      this.stop();
      return false;
    }

    this.start();
    return true;
  }

  playRollAccent() {
    this.ensureCtx();
    this.playKoto(329.63);
    setTimeout(() => this.playKoto(440.0), 70);
    setTimeout(() => this.playKoto(523.25), 140);
  }

  playTaikoFill() {
    this.ensureCtx();
    this.playTaiko(true);
    setTimeout(() => this.playTaiko(false), 110);
    setTimeout(() => this.playTaiko(false), 220);
  }
}

const audio = new MultiSongAudio((message) => {
  ui.dealerLine.textContent = message;
});

buildCharacterPicker();
applyRosterToUi();
ui.songSelect.value = "local_bounce";

ui.betCho.addEventListener("click", () => playRound("Cho"));
ui.betHan.addEventListener("click", () => playRound("Han"));
ui.restartBtn.addEventListener("click", resetGame);
ui.playerSpriteSelect.addEventListener("change", handlePlayerCharacterChange);
ui.songSelect.addEventListener("change", () => {
  audio.setSong(ui.songSelect.value);
});
ui.musicToggle.addEventListener("click", () => {
  const on = audio.toggle();
  ui.musicToggle.classList.toggle("active", on);
  ui.musicToggle.textContent = on ? "Stop Music" : "Start Music";
});

resetGame();
