# 🏖️ Sandpiles Algorithm

> **Advanced computational simulation of sandpile dynamics with automated stabilization protocols**

[![C](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
## 🚀 Overview

This cutting-edge implementation explores the fascinating world of **sandpile cellular automata** - a mathematical model that demonstrates emergent complexity from simple rules. Our algorithm computes the sum of two 3×3 sandpile grids and applies intelligent stabilization protocols to achieve equilibrium states.

## 🧠 The Problem Explained

### Mathematical Foundation
The **Sandpile Model** is a cellular automaton that simulates the behavior of sand grains falling and redistributing on a discrete grid. This model was introduced by Bak, Tang, and Wiesenfeld as an example of **self-organized criticality**.

### Problem Statement
Given two 3×3 grids representing sandpiles, we need to:
1. **Add** the corresponding cells of both grids
2. **Stabilize** the resulting grid by applying toppling rules
3. **Visualize** each unstable state during the stabilization process

### The Toppling Rule
When a cell contains more than 3 grains, it becomes **unstable** and must "topple":
- The unstable cell **loses 4 grains**
- Each of its **4 orthogonal neighbors** (up, down, left, right) **gains 1 grain**
- If neighbors are at the grid boundary, those grains are **lost** (fall off the edge)

### Cascade Effect
The toppling of one cell can create new unstable cells, leading to a **cascade reaction** that continues until the entire grid reaches a stable state where no cell contains more than 3 grains.

### Real-World Example
```
Initial Addition:
3 3 3   1 3 1     4 6 4
3 3 3 + 3 3 3  =  6 6 6  (Unstable!)
3 3 3   1 3 1     4 6 4

Step 1 - Toppling:
4 6 4  →  2 5 2  (cells with 4+ grains topple simultaneously)
6 6 6     5 6 5
4 6 4     2 5 2

Step 2 - More Toppling:
2 5 2  →  4 2 4  (center cell with 6 grains topples)
5 6 5     2 6 2
2 5 2     4 2 4

... (continues until stable)

Final Stable State:
2 2 2
2 2 2
2 2 2
```

### Computational Complexity
- **Time Complexity**: O(n) where n is the number of toppling iterations
- **Space Complexity**: O(1) - uses only a temporary 3×3 grid for calculations
- **Convergence**: Always guaranteed to reach a stable state (proven mathematically)

## 🎯 Algorithm Flow
```
Input: Two 3×3 grids → Addition → Stabilization Loop → Stable Output
```

## 📚 Learning Resources

- 🎥 [Sandpiles - Numberphile](https://www.youtube.com/watch?v=1MtEUErz7Gg) - Visual explanation of sandpile mathematics

## ⚡ Quick Start

### Build System
```bash
# Compile with advanced error checking
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-sandpiles.c -o sandpiles

# Execute simulation
./sandpiles
```

### API Usage
```c
#include "sandpiles.h"

// Initialize grids
int grid1[3][3] = {{3, 3, 3}, {3, 3, 3}, {3, 3, 3}};
int grid2[3][3] = {{1, 3, 1}, {3, 3, 3}, {1, 3, 1}};

// Compute stabilized sum
sandpiles_sum(grid1, grid2);
// Result stored in grid1: {{2, 2, 2}, {2, 2, 2}, {2, 2, 2}}
```

## 🏗️ Architecture

```
sandpiles/
├── 📄 sandpiles.h      # Core API definitions
├── ⚙️ 0-sandpiles.c    # Algorithm implementation
├── 🧪 0-main.c         # Test suite A
├── 🧪 1-main.c         # Test suite B
└── 📖 README.md        # Documentation
```

## 🔧 Technical Specifications

| Requirement | Specification |
|-------------|---------------|
| **Environment** | Ubuntu 14.04 LTS |
| **Compiler** | GCC 4.8.4 |
| **Code Style** | Betty Standard |
| **Memory Model** | Static allocation only |
| **Function Limit** | 5 per file |
| **Global Variables** | Prohibited |

## 🎨 Features

- ✨ **Real-time Visualization**: Live display of each toppling iteration
- 🔄 **Automatic Stabilization**: Intelligent cascade handling
- 🚫 **Zero Memory Leaks**: Static memory management
- 📊 **Mathematical Accuracy**: Precise grain redistribution
- 🛡️ **Error-Free Compilation**: Strict compiler flags compliance


## 🎓 Educational Value

This project demonstrates:
- **Cellular Automata** principles
- **Emergent Behavior** from simple rules
- **Mathematical Modeling** in computational systems
- **Algorithm Optimization** techniques

---

