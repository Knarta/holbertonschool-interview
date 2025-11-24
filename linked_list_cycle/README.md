# 🔄 Linked List Cycle Detection

> **Technical Interview Challenge**: Detect cycles in singly linked lists with optimal efficiency

## 🎯 Mission

Build a lightning-fast cycle detection algorithm for singly linked lists using the legendary **Floyd's Cycle Detection** (Tortoise and Hare) method.

## ⚡ Core Function

```c
int check_cycle(listint_t *list);
```

**Return Values:**
- `0` → No cycle detected
- `1` → Cycle found! 🎯

## 🚀 Performance Requirements

- **Time Complexity**: O(n) - Linear scanning
- **Space Complexity**: O(1) - Constant memory usage
- **Efficiency**: Zero extra memory allocations

## 🔧 Allowed Functions

Only these battle-tested functions are permitted:
- `write`, `printf`, `putchar`, `puts`
- `malloc`, `free`

## 📁 Project Structure

```
linked_list_cycle/
├── 0-check_cycle.c    # 🧠 Core algorithm implementation
├── lists.h           # 📋 Structure definitions & prototypes
├── 0-linked_lists.c  # 🛠️  Utility functions
└── 0-main.c         # 🧪 Test suite
```

## 🏃‍♂️ Quick Start

```bash
# Compile with strict warnings
gcc -Wall -Werror -Wextra -pedantic 0-main.c 0-check_cycle.c 0-linked_lists.c -o cycle

# Run the test suite
./cycle
```

## 🧠 Algorithm: Tortoise & Hare

The **Floyd's Cycle Detection Algorithm** uses two pointers moving at different speeds:

- **🐢 Tortoise (Slow)**: Moves 1 node at a time
- **🐰 Hare (Fast)**: Moves 2 nodes at a time

**Magic happens when:**
- ✅ **Cycle exists** → Hare catches up to Tortoise
- ❌ **No cycle** → Hare reaches the end first

This elegant approach guarantees optimal performance with minimal memory footprint.

## 🎨 Code Style

- Betty style compliance required
- No global variables allowed
- Maximum 5 functions per file
- Include guards mandatory

---

*Ready to master cycle detection? Let's make those linked lists cycle-proof! 🚀*
