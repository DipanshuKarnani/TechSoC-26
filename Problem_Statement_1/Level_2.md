# 🔍 Level 2 — The Pattern Watcher

[![Difficulty](https://img.shields.io/badge/Difficulty-Intermediate-e67e22?style=flat-square)](#)
[![Concepts](https://img.shields.io/badge/Concepts-Modular%20Design%20|%20Toroidal%20Topology%20|%20Cycle%20Detection%20|%20File%20I%2FO-0d6efd?style=flat-square)](#)

---

## Background

The initial colony telemetry from Level 1 was a success! However, the astrobiologists noted two key limitations in the basic setup:

1. Cells migrating towards the border of the microchip simply fell off and died due to artificial bounded borders. In real toroidal microchips, the grid wraps around continuously!
2. Manually calculating whether an organism will oscillate forever, freeze into a still life, or die out takes too much time.

The lab director has issued a directive:

> *"Upgrade the simulator into an intelligent pattern recognition and telemetry workstation."*

---

## Your Task

Build upon your Level 1 code and implement modular features to analyze pattern behaviors:

| # | Feature | Description |
|---|---|---|
| 1 | **Toroidal Wrap-Around Mode** | Cells at the edge connect seamlessly to the opposite edge (donut topology). |
| 2 | **Automated Pattern Classifier** | Detect if a pattern is a **Still Life**, **Oscillator (with period $P$)**, **Extinct**, or **Active** within $K$ steps. |
| 3 | **Population History Bar Chart** | Display an ASCII visual graph of population size across generations. |
| 4 | **Center of Mass & Bounding Box** | Compute the bounding box dimensions ($H \times W$) and center of mass $(r_{avg}, c_{avg})$ of live cells. |
| 5 | **Save Telemetry Report** | Export the run log and analysis metrics to a file. |
| 6 | **Load Pattern from File** | Read initial state and grid configurations from a `.txt` file. |

---

## Rules

- Any programming language (Python, C++, Java, Rust, JavaScript, etc.)
- Single program file, runs in your terminal
- No GUI frameworks or third-party game libraries — clean modular code

---

## Concepts You'll Use

| Concept | Description |
|---|---|
| Modular Functions | Structuring logic into distinct callable components |
| Toroidal Coordinates | Wrap-around indexing using modulo arithmetic: `(r + dr + R) % R` |
| State Hashing / History | Storing past grid snapshots to identify repeated cyclic states |
| Center of Mass | Calculating average coordinates: $\bar{r} = \frac{\sum r_i}{N}, \bar{c} = \frac{\sum c_i}{N}$ |
| File Streams | Reading configuration files and writing output reports |

---

## Feature Specifications & Test Cases

---

### Feature 1: Toroidal Wrap-Around Mode

In toroidal mode, row $-1$ maps to row $R-1$, and row $R$ maps to row $0$. Similarly, column $-1$ maps to column $C-1$, and column $C$ maps to column $0$.

<details>
<summary><strong>🧪 Feature 1 — Test Case 1: Blinker on Grid Border</strong></summary>
<br>

*A horizontal blinker split across the right and left edges seamlessly connects and oscillates.*

**Input:**
```
toroidal
3 3
1
#.#
...
...
```

**Output:**
```
Mode: Toroidal
Initial Population: 2
Final Population: 3
Final Grid:
#..
#..
#..
```
</details>

<details>
<summary><strong>🧪 Feature 1 — Test Case 2: Glider Boundary Traverse</strong></summary>
<br>

*A glider wraps across the border and continues moving.*

**Input:**
```
toroidal
4 4
4
.#..
..#.
###.
....
```

**Output:**
```
Mode: Toroidal
Initial Population: 5
Final Population: 5
Final Grid:
#...
.#.#
....
#...
```
</details>

---

### Feature 2: Automated Pattern Classifier

Simulate the grid step-by-step up to a maximum limit of $K$ steps (default $K=100$) and identify its state:

- **`Extinct`**: All cells have died (population = 0 at step $S$).
- **`Still Life`**: The grid configuration at step $S$ is identical to step $S-1$ (Period 1).
- **`Oscillator (Period P)`**: The grid configuration at step $S$ is identical to a previous step $S - P$ where $P \ge 2$.
- **`Active`**: The grid has not repeated or died out within $K$ steps.

<details>
<summary><strong>🧪 Feature 2 — Test Case 1: Block (Still Life)</strong></summary>
<br>

**Input:**
```
classify
4 4
50
....
.##.
.##.
....
```

**Output:**
```
Classification: Still Life
Stable at Step: 0
Period: 1
Final Population: 4
```
</details>

<details>
<summary><strong>🧪 Feature 2 — Test Case 2: Blinker (Oscillator Period 2)</strong></summary>
<br>

**Input:**
```
classify
5 5
50
.....
.###.
.....
.....
.....
```

**Output:**
```
Classification: Oscillator
Period: 2
First Repeat Step: 2 (matches Step 0)
Population: 3
```
</details>

<details>
<summary><strong>🧪 Feature 2 — Test Case 3: Toad (Oscillator Period 2)</strong></summary>
<br>

**Input:**
```
classify
6 6
50
......
..###.
.###..
......
......
......
```

**Output:**
```
Classification: Oscillator
Period: 2
First Repeat Step: 2 (matches Step 0)
Population: 6
```
</details>

<details>
<summary><strong>🧪 Feature 2 — Test Case 4: Extinction</strong></summary>
<br>

**Input:**
```
classify
3 3
50
#..
.##
...
```

**Output:**
```
Classification: Extinct
Extinction Step: 2
Final Population: 0
```
</details>

---

### Feature 3: Population History Bar Chart

Print a visual text-based chart showing population at each generation from $0$ to $G$. Each `*` represents 1 live cell.

<details>
<summary><strong>🧪 Feature 3 — Test Case 1: Pulsing Population Chart</strong></summary>
<br>

**Input:**
```
chart
6 6
4
......
.##...
.##...
...##.
...##.
......
```

**Output:**
```
Gen 0 (8): ********
Gen 1 (6): ******
Gen 2 (8): ********
Gen 3 (6): ******
Gen 4 (8): ********
```
</details>

<details>
<summary><strong>🧪 Feature 3 — Test Case 2: Decaying Population Chart</strong></summary>
<br>

**Input:**
```
chart
3 3
3
#..
.##
...
```

**Output:**
```
Gen 0 (3): ***
Gen 1 (2): **
Gen 2 (0): 
Gen 3 (0): 
```
</details>

---

### Feature 4: Center of Mass & Bounding Box

For a given grid with $N$ live cells located at coordinates $(r_1, c_1), (r_2, c_2), \dots, (r_N, c_N)$:
- **Bounding Box:** $H = (r_{max} - r_{min} + 1)$, $W = (c_{max} - c_{min} + 1)$
- **Center of Mass:** $(\bar{r}, \bar{c}) = \left(\frac{\sum r_i}{N}, \frac{\sum c_i}{N}\right)$ rounded to 2 decimal places.
- If $N = 0$, print `No live cells`.

<details>
<summary><strong>🧪 Feature 4 — Test Case 1: Glider Metrics</strong></summary>
<br>

**Input:**
```
metrics
5 5
0
.#...
..#..
###..
.....
.....
```

**Output:**
```
Live Cells: 5
Bounding Box: 3 x 3 (Rows 0-2, Cols 0-2)
Center of Mass: (1.40, 1.00)
```
</details>

<details>
<summary><strong>🧪 Feature 4 — Test Case 2: Empty Grid</strong></summary>
<br>

**Input:**
```
metrics
3 3
0
...
...
...
```

**Output:**
```
Live Cells: 0
Bounding Box: 0 x 0
Center of Mass: N/A
```
</details>

---

### Feature 5 & 6: File Import and Report Export

Enable reading grid files and writing comprehensive analysis logs.

<details>
<summary><strong>🧪 Feature 5 & 6 — Test Case: File Workflow</strong></summary>
<br>

Given a file `colony.txt`:
```
5 5
2
.....
.###.
.....
.....
.....
```

**Input:**
```
load colony.txt
save report.txt
```

**Output in Terminal:**
```
Loaded 5x5 grid from colony.txt (Generations: 2)
Simulation complete. Report saved to report.txt.
```

**Generated `report.txt`:**
```
--- Conway Simulation Telemetry ---
Grid Dimensions: 5 x 5
Generations Simulated: 2
Initial Population: 3
Final Population: 3
Peak Population: 3
Classification: Oscillator (Period 2)
Final State:
.....
.###.
.....
.....
.....
```
</details>

---

*Ready for the ultimate challenge? Head over to [Level 3 — The Automata Architect](Level_3.md)!*
