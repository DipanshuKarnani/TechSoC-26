# ⏱️ Level 3 — Real-Time Evolution

[![Difficulty](https://img.shields.io/badge/Difficulty-Beginner%20to%20Intermediate-2ecc71?style=flat-square)](#)
[![Concepts](https://img.shields.io/badge/Concepts-Timed%20Loops%20|%20Screen%20Clearing%20|%20Reusing%20L2%20Logic-0d6efd?style=flat-square)](#)

---

## Background

Levels 1 and 2 print only the final grid after all generations are computed. Level 3 prints each generation as it happens, one frame at a time, with a short delay between frames.

---

## Your Task

| # | Feature | Description |
|---|---|---|
| 1 | **Real-Time Playback** | Print each generation, pause briefly, clear the screen, print the next. |
| 2 | **Smart Auto-Stop** | Stop early if the pattern reaches Still Life, Oscillator, or Extinct — reuse your Level 2 classifier logic. |
| 3 *(optional bonus)* | **Adjustable Speed** | Let the user set the delay between frames in milliseconds. |

---

## Rules

- Any programming language
- Single program file, runs in your terminal
- No GUI frameworks or third-party libraries
- Using your language's built-in delay function (`sleep`, `Thread.sleep`, `setTimeout`, etc.) is allowed — no multithreading needed
- Because output is printed in real time, plain captured text won't fully show the effect. Include a short screen recording or GIF along with your code.

---

## Concepts You'll Use

| Concept | Description |
|---|---|
| Timed Loops | Pausing between iterations so frames appear at a readable pace |
| Screen Clearing | Clearing the previous frame before printing the next |
| Reusing Classifier Logic | Applying your Level 2 state-hashing logic to detect when to stop early |

**Delay:** `time.sleep(1)` (Python), `std::this_thread::sleep_for(std::chrono::milliseconds(500))` (C++, in `<thread>` but doesn't spawn a thread), `Thread.sleep(1000)` (Java), `await new Promise(r => setTimeout(r, 1000))` (JS).

**Clearing:** `os.system('cls' if os.name == 'nt' else 'clear')`, or print the ANSI code `"\033[H\033[J"` directly.

---

## Feature Specifications & Test Cases

### Feature 1: Real-Time Playback

Each frame prints a header (generation number, population) followed by the grid, then pauses, clears, and prints the next frame.

<details>
<summary><strong>🧪 Test Case: Blinker (delay = 1s)</strong></summary>
<br>

**Input:**
```
animate
5 5
2
.....
.###.
.....
.....
.....
```

**Frames (each replaces the previous one on screen):**
```
Generation: 0   Population: 3
.....
.###.
.....
.....
.....
```
```
Generation: 1   Population: 3
..#..
..#..
..#..
.....
.....
```
```
Generation: 2   Population: 3
.....
.###.
.....
.....
.....
Simulation complete.
```
</details>

---

### Feature 2: Smart Auto-Stop

While animating, check each new state against previously seen states:
- Population reaches 0 → `Extinct at Generation <S>`
- Matches previous state → `Still Life reached at Generation <S>`
- Matches a state seen `P` steps ago (`P ≥ 2`) → `Oscillator (Period <P>) reached at Generation <S>`
- Otherwise keep going up to the generation limit `G`

<details>
<summary><strong>🧪 Test Case: Blinker with High Generation Limit</strong></summary>
<br>

**Input:**
```
animate
5 5
50
.....
.###.
.....
.....
.....
```

**Result:** Frames play for Generation 0–2 as above. At Generation 2, the state matches Generation 0, so it stops instead of continuing to 50:
```
Generation: 2   Population: 3
.....
.###.
.....
.....
.....
Pattern stabilized: Oscillator (Period 2)
Stopped early at Generation 2 (limit was 50)
```
</details>

---

### Feature 3 *(Optional Bonus)*: Adjustable Speed

Accept a delay value (in milliseconds) as an extra input instead of a fixed 1-second delay.

<details>
<summary><strong>🧪 Test Case: Custom Delay</strong></summary>
<br>

**Input:**
```
animate
5 5
2
200
.....
.###.
.....
.....
.....
```
*(`200` = delay in ms, given right after the generation count.)*

Same frame sequence as Feature 1, shown ~200ms apart instead of 1s.
</details>

---

## How to Run Your Submission

Add a short comment block at the top of your code (or a separate `RUN.md`) telling us exactly how to run it. Include:

- Language and version used
- Compile command, if your language needs one (e.g. `g++ solution.cpp -o sim`)
- Exact run command (e.g. `python solution.py`, `./sim`)
- Any input file names or arguments your program expects

Example:
```
// Language: C++17
// Compile: g++ level3.cpp -o level3
// Run: ./level3
// Input: enter values directly in terminal when prompted, or pipe a file: ./level3 < input.txt
```

Submissions without clear run instructions may take longer to evaluate.
