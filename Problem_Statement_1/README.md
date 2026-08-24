# 🦠 Problem Statement 1: The Silicon Biosphere (Conway's Game of Life)

Welcome to **Problem Statement 1**! In this challenge, you will explore **Cellular Automata** by implementing and analyzing **Conway's Game of Life**, one of the most famous and fascinating simulations in computer science.

Discovered by mathematician **John Horton Conway** in 1970, the Game of Life is a "zero-player game" whose evolution is determined entirely by its initial state. A simple set of four local rules gives rise to astonishing complexity: stable ecosystems, oscillating clocks, self-replicating organisms, and spaceships traveling through infinite digital space.

To guide you from foundational grid manipulation to advanced automata engineering, this problem statement is split into **three progressive levels**:

---

### 📍 The Levels

| Level | Title | Difficulty | Core Focus |
|---|---|---|---|
| [**🌱 Level 1**](Level_1.md) | **Genesis of the Grid** | Beginner | 2D Grids, 8-Neighbor Moore Counting, Conway's 4 Rules, Bounded Grid Evolution |
| [**🔍 Level 2**](Level_2.md) | **The Pattern Watcher** | Intermediate | Toroidal (Wrap-around) Topologies, Cycle Detection (Oscillators, Still Lifes), File I/O, Population Trends |
| [**⚡ Level 3**](Level_3.md) | **The Automata Architect** | Advanced | Generic $B.../S...$ Rule Engines, Standard RLE File Parser, Dynamic Bounding Box & Longevity Tracking |

---

## 📜 The Four Rules of Life

Every cell on a two-dimensional grid is either **Alive** (`#` or `1`) or **Dead** (`.` or `0`). In each tick of time (generation), each cell examines its **8 immediate neighbors** (Moore neighborhood: horizontally, vertically, and diagonally):

1. **Underpopulation:** Any live cell with **fewer than 2** live neighbors dies.
2. **Survival:** Any live cell with **2 or 3** live neighbors lives on to the next generation.
3. **Overpopulation:** Any live cell with **more than 3** live neighbors dies.
4. **Reproduction:** Any dead cell with **exactly 3** live neighbors becomes a live cell.

> All births and deaths occur **simultaneously** in each generation step.

---

## 🌟 Famous Patterns Preview

```
   Still Life (Block)         Oscillator (Blinker)          Spaceship (Glider)
        ##                         ...                            .#.
        ##                         ###                            ..#
                                   ...                            ###
     (Period 1)                 (Period 2)                  (Moves across grid)
```

---

## 🚀 How to Begin

1. Start with [**Level 1 — Genesis of the Grid**](Level_1.md) to implement the core simulation engine.
2. Once your Level 1 passes all test cases, proceed to [**Level 2**](Level_2.md) and [**Level 3**](Level_3.md) to build pattern classification and standard file parsing.
3. You may use any programming language (Python, C++, Java, Rust, JavaScript, etc.).

Have fun exploring the emergence of digital life!
