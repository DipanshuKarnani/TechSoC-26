# 🌱 Level 1 — Genesis of the Grid

[![Difficulty](https://img.shields.io/badge/Difficulty-Beginner-2ea44f?style=flat-square)](#)
[![Concepts](https://img.shields.io/badge/Concepts-2D%20Arrays%20|%20Nested%20Loops%20|%20Conditions%20|%20Functions-0d6efd?style=flat-square)](#)

---

## Background

The Computational Astrobiology Laboratory at IIT Indore has made a startling discovery: microscopic synthetic cells thriving on the surface of an ancient Martian microchip!

These digital organisms reproduce, starve, and cluster in an orderly lattice according to mathematical rules first proposed by John Conway. The lead researcher has tasked you with building the foundational simulation engine to observe how an initial colony evolves over time on a bounded grid.

> *"We need to simulate these digital lifeforms with absolute precision — one tick of the clock at a time."*

---

## The Four Rules of Conway's Game of Life

In each step (generation), every cell on an $R \times C$ grid looks at its **8 surrounding neighbors** (Moore neighborhood: top-left, top, top-right, left, right, bottom-left, bottom, bottom-right).

Cells outside the grid boundaries are considered **dead** (fixed/dead boundary condition).

1. **Underpopulation:** Any live cell with **strictly fewer than 2** live neighbors dies.
2. **Survival:** Any live cell with **2 or 3** live neighbors remains alive.
3. **Overpopulation:** Any live cell with **strictly more than 3** live neighbors dies.
4. **Reproduction:** Any dead cell with **exactly 3** live neighbors becomes a live cell.

> **Crucial Note:** All cells in generation $t$ update **simultaneously** to produce generation $t + 1$. A cell's new state must NOT affect the calculation of its neighbor's state in the same generation.

---

## Your Task

Write a program that:

1. Reads the grid dimensions: rows `R` and columns `C`.
2. Reads the number of generations to simulate `G`.
3. Reads `R` lines of text, each containing `C` characters:
   - `.` represents a **dead cell**
   - `#` represents a **live cell**
4. Simulates the grid for `G` generations.
5. Calculates and prints:
   - **Initial Population:** Total count of live cells at generation 0
   - **Final Population:** Total count of live cells after generation $G$
   - **Peak Population:** The maximum number of live cells observed at any generation from $0$ to $G$ (inclusive)
   - **Final Grid State:** The $R \times C$ grid after $G$ generations

---

## Rules

- Use **any programming language** (Python, C++, C, Java, Rust, JavaScript, etc.)
- Write a single program file and run it in your terminal
- **No GUI, no web app, no framework** — standard terminal I/O only
- **No external third-party simulation libraries**

---

## How to Read the Test Cases

- **Input** provides the raw values: `R`, `C`, `G`, followed by the initial grid rows.
- **Output** displays the summary metrics followed by the final grid configuration.

---

## Input Format

```
R C
G
<row 1>
<row 2>
...
<row R>
```

- Line 1: Two integers `R` and `C` ($1 \le R, C \le 100$) — rows and columns.
- Line 2: An integer `G` ($0 \le G \le 1000$) — number of generations to simulate.
- Next `R` lines: A string of length `C` containing only `.` and `#`.

---

## Output Format

```
Initial Population: <int>
Final Population: <int>
Peak Population: <int>
Final Grid:
<row 1>
<row 2>
...
<row R>
```

---

## Concepts You'll Use

| Concept | Description |
|---|---|
| 2D Arrays / Matrices | Representing the $R \times C$ grid of cells |
| Nested Loops | Iterating across rows and columns to inspect neighbors |
| Moore Neighborhood | Checking 8 directions $(dr \in \{-1, 0, 1\}, dc \in \{-1, 0, 1\})$ |
| Double Buffering | Keeping a copy of the previous grid to update states simultaneously |
| Boundary Checks | Ensuring neighbor coordinates remain within $[0, R-1]$ and $[0, C-1]$ |
| State Tracking | Tracking initial, peak, and final live cell counts |

---

## Test Cases

<details>
<summary><strong>🧪 Test Case 1 — The Blinker (1 Generation)</strong></summary>
<br>

*A horizontal line of 3 cells rotates to a vertical line.*

**Input:**
```
5 5
1
.....
.###.
.....
.....
.....
```

**Output:**
```
Initial Population: 3
Final Population: 3
Peak Population: 3
Final Grid:
..#..
..#..
..#..
.....
.....
```
</details>

<details>
<summary><strong>🧪 Test Case 2 — The Blinker (2 Generations)</strong></summary>
<br>

*After 2 generations, the blinker oscillates back to its original horizontal state.*

**Input:**
```
5 5
2
.....
.###.
.....
.....
.....
```

**Output:**
```
Initial Population: 3
Final Population: 3
Peak Population: 3
Final Grid:
.....
.###.
.....
.....
.....
```
</details>

<details>
<summary><strong>🧪 Test Case 3 — The Block (Still Life, 5 Generations)</strong></summary>
<br>

*A 2x2 square is a still life: each cell has exactly 3 neighbors, so it never changes.*

**Input:**
```
4 4
5
....
.##.
.##.
....
```

**Output:**
```
Initial Population: 4
Final Population: 4
Peak Population: 4
Final Grid:
....
.##.
.##.
....
```
</details>

<details>
<summary><strong>🧪 Test Case 4 — The Glider (4 Generations)</strong></summary>
<br>

*A glider moves 1 diagonal step across the grid every 4 generations.*

**Input:**
```
5 5
4
.#...
..#..
###..
.....
.....
```

**Output:**
```
Initial Population: 5
Final Population: 5
Peak Population: 5
Final Grid:
.....
..#..
...#.
.###.
.....
```
</details>

<details>
<summary><strong>🧪 Test Case 5 — The Toad Oscillator</strong></summary>
<br>

*A 6-cell period-2 oscillator.*

**Input:**
```
6 6
1
......
..###.
.###..
......
......
......
```

**Output:**
```
Initial Population: 6
Final Population: 6
Peak Population: 6
Final Grid:
...#..
.#..#.
.#..#.
..#...
......
......
```
</details>

<details>
<summary><strong>🧪 Test Case 6 — The Beacon Oscillator</strong></summary>
<br>

*Two touching 2x2 blocks oscillate in a period of 2.*

**Input:**
```
6 6
1
......
.##...
.##...
...##.
...##.
......
```

**Output:**
```
Initial Population: 8
Final Population: 6
Peak Population: 8
Final Grid:
......
.##...
.#....
....#.
...##.
......
```
</details>

<details>
<summary><strong>🧪 Test Case 7 — Underpopulation & Extinction</strong></summary>
<br>

*Isolated cells have 0 neighbors and immediately perish.*

**Input:**
```
3 3
1
#..
...
..#
```

**Output:**
```
Initial Population: 2
Final Population: 0
Peak Population: 2
Final Grid:
...
...
...
```
</details>

<details>
<summary><strong>🧪 Test Case 8 — Overpopulation & Birth Surge</strong></summary>
<br>

*A central cross pattern triggers births and overpopulation deaths simultaneously.*

**Input:**
```
3 3
1
.#.
###
.#.
```

**Output:**
```
Initial Population: 5
Final Population: 8
Peak Population: 8
Final Grid:
###
#.#
###
```
</details>

<details>
<summary><strong>🧪 Test Case 9 — Zero Generations (Edge Case)</strong></summary>
<br>

*When G = 0, the grid remains identical to the initial state.*

**Input:**
```
3 3
0
.##
.#.
...
```

**Output:**
```
Initial Population: 3
Final Population: 3
Peak Population: 3
Final Grid:
.##
.#.
...
```
</details>

<details>
<summary><strong>🧪 Test Case 10 — Bounded Boundary Decay</strong></summary>
<br>

*Cells on the border have fewer neighbors because out-of-bound cells are dead.*

**Input:**
```
4 4
1
####
....
....
####
```

**Output:**
```
Initial Population: 8
Final Population: 8
Peak Population: 8
Final Grid:
.##.
.##.
.##.
.##.
```
</details>

---

*Once you're confident Level 1 works, level up your toolkit in [Level 2 — The Pattern Watcher](Level_2.md).*
