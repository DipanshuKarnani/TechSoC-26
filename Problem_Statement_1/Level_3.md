# ⚡ Level 3 — The Automata Architect

[![Difficulty](https://img.shields.io/badge/Difficulty-Advanced-9b59b6?style=flat-square)](#)
[![Concepts](https://img.shields.io/badge/Concepts-String%20Parsing%20|%20Rule%20Engines%20|%20RLE%20Format%20|%20Dynamic%20Coordinates-0d6efd?style=flat-square)](#)

---

## Background

The astrobiology team has discovered that Martian organisms do not all obey Conway's standard rules. Some mutations survive in chaotic dense environments (*HighLife*), others reproduce with lightning speed like crystals (*Seeds*), while others thrive in inverted light-dark environments (*Day & Night*).

Furthermore, the scientific community shares cellular automata patterns using the **RLE (Run Length Encoded)** standard file format rather than raw ASCII grids.

The lab needs you to construct the ultimate cellular automata engine capable of simulating **any arbitrary Life-like rule** and ingesting industry-standard **RLE files**!

---

## Your Task

Implement an advanced cellular automata engine supporting the following components:

| # | Feature | Description |
|---|---|---|
| 1 | **Generic Life-Like Rule Engine ($B.../S...$)** | Parse and simulate custom birth and survival rules (e.g. `B3/S23`, `B36/S23`, `B2/S`, `B3678/S34678`). |
| 2 | **Standard RLE File Parser** | Parse and load patterns stored in the official **Run Length Encoded (.rle)** format. |
| 3 | **Dynamic / Unbounded Bounding Box** | Track alive cells dynamically without rigid grid walls, auto-fitting the bounding box as the colony expands. |
| 4 | **Cell Longevity Heatmap** | Track the age of every cell (how many consecutive generations it has survived continuously). |

---

## Rules

- Use **any programming language** (Python, C++, Java, Rust, Go, etc.)
- Single program file or modular project, run from terminal
- **No external third-party automata libraries** — write the parsing and rule engine from scratch

---

## Concepts You'll Use

| Concept | Description |
|---|---|
| Rule Notation Parsing | Deconstructing `B<born_counts>/S<survive_counts>` into integer lookup sets |
| RLE Tokenization | Parsing run counts (`3o`, `5b`), line breaks (`$`), and terminators (`!`) |
| Sparse / Coordinate Sets | Representing infinite grids using sets of `(row, col)` tuples |
| Longevity Matrices | Keeping a 2D integer counter for consecutive living generations |

---

## Detailed Specifications & Test Cases

---

### Feature 1: Generalized $B.../S...$ Rule Engine

A Life-like rule is expressed as `B<digits>/S<digits>`:
- `B<digits>`: Numbers of live neighbors required for a dead cell to be **Born**.
- `S<digits>`: Numbers of live neighbors required for a live cell to **Survive**.
- Any other neighbor count causes the cell to die or remain dead.

| Rule Name | Notation | Characteristic |
|---|---|---|
| **Conway's Life** | `B3/S23` | Classic standard game of life |
| **HighLife** | `B36/S23` | Features a famous self-replicating pattern |
| **Seeds** | `B2/S` | All live cells die every step; 2 neighbors spawn new cells |
| **Life without Death** | `B3/S012345678` | Cells never die; patterns grow like ink spreading on paper |
| **Diamoeba** | `B35678/S5678` | Forms large diamond-shaped cell colonies |

<details>
<summary><strong>🧪 Feature 1 — Test Case 1: HighLife (B36/S23)</strong></summary>
<br>

*Under HighLife, a dead cell with 6 live neighbors is born (unlike standard Conway).*

**Input:**
```
rule B36/S23
5 5
1
.###.
#...#
#...#
#...#
.###.
```

**Output:**
```
Rule: B36/S23
Initial Population: 12
Final Population: 16
Peak Population: 16
Final Grid:
.###.
#.#.#
##.##
#.#.#
.###.
```
</details>

<details>
<summary><strong>🧪 Feature 1 — Test Case 2: Seeds (B2/S)</strong></summary>
<br>

*Under Seeds, live cells always die (survival set is empty), and cells are born with exactly 2 neighbors.*

**Input:**
```
rule B2/S
4 4
1
....
.##.
....
....
```

**Output:**
```
Rule: B2/S
Initial Population: 2
Final Population: 4
Peak Population: 4
Final Grid:
.##.
....
.##.
....
```
</details>

---

### Feature 2: Standard RLE (Run Length Encoded) Parser

The RLE format is the standard format used by LifeWiki and cellular automata researchers:
1. **Comments:** Lines starting with `#` are ignored (e.g. `#N`, `#O`, `#C`).
2. **Header:** `x = <width>, y = <height>, rule = <rule_string>`
3. **Encoded Rows:**
   - `b` = dead cell
   - `o` = live cell
   - `<count><tag>` = run of `<count>` cells of type `<tag>` (e.g., `3o` = `ooo`, `4b` = `bbbb`). If count is omitted, it defaults to 1.
   - `$` = end of line / next row. `<count>$` means skip `<count>` rows.
   - `!` = end of pattern data.

<details>
<summary><strong>🧪 Feature 2 — Test Case 1: Glider RLE Decode & Step</strong></summary>
<br>

**Input (RLE file `glider.rle`):**
```
#N Glider
#O Richard K. Guy
#C The smallest spaceship.
x = 3, y = 3, rule = B3/S23
bob$2bo$3o!
```

**Execution Command:**
```
rle glider.rle 1
```

**Output:**
```
Pattern Name: Glider
Bounding Box: 3 x 3
Rule: B3/S23
Initial Grid (0):
.#.
..#
###

State after Generation 1:
...
#.#
.##
.#.
```
</details>

<details>
<summary><strong>🧪 Feature 2 — Test Case 2: Run-Length Compression Decode</strong></summary>
<br>

**Input (RLE string):**
```
x = 6, y = 3, rule = B3/S23
2b3o$3o2bo$bo!
```

**Decoded Grid (Generation 0):**
```
..###.
###..#
.#....
```
</details>

---

### Feature 3: Dynamic Bounding Box & Expansion Tracking

Instead of capping organisms within fixed boundary walls, track live cells dynamically across generations and compute the expanding bounding box $(W \times H)$.

<details>
<summary><strong>🧪 Feature 3 — Test Case 1: Expanding Glider Trajectory</strong></summary>
<br>

**Input:**
```
dynamic B3/S23
3 3
4
.#.
..#
###
```

**Output:**
```
Gen 0: Pop = 5 | Box: (0,0) to (2,2) [3 x 3]
Gen 1: Pop = 5 | Box: (1,0) to (3,2) [3 x 3]
Gen 2: Pop = 5 | Box: (1,1) to (3,3) [3 x 3]
Gen 3: Pop = 5 | Box: (1,1) to (3,3) [3 x 3]
Gen 4: Pop = 5 | Box: (1,1) to (3,3) [3 x 3]
Displacement: (Row +1, Col +1)
```
</details>

---

### Feature 4: Cell Longevity Heatmap

Track for how many consecutive generations each cell has remained alive:
- A newly born cell has age `1`.
- If it survives the next generation, its age becomes `2`, `3`, etc.
- When a cell dies, its age resets to `0` (`.`).

<details>
<summary><strong>🧪 Feature 4 — Test Case 1: Blinker vs Block Longevity</strong></summary>
<br>

**Input:**
```
longevity
4 4
3
.##.
.##.
....
....
```

*(Block survives 3 generations without dying)*

**Output:**
```
Longevity Heatmap (Gen 3):
. 4 4 .
. 4 4 .
. . . .
. . . .

(Cells at [0,1], [0,2], [1,1], [1,2] have lived continuously for 4 generations: Gen 0, 1, 2, 3)
```
</details>

---

## 🏆 Summary of Achievements

Congratulations! By completing Level 3, you have engineered:
- An ultra-flexible **Universal Life-Like Automata Engine**
- A standards-compliant **RLE File Format Parser**
- Dynamic **Coordinate Tracking** and **Cell Longevity Heatmaps**

You are now ready to simulate complex automata systems, guns, spaceships, and self-replicating computers!
