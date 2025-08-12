# 🔐 Lockboxes Algorithm

> **BFS-based solution for box unlocking challenge**

## 🎯 Problem
Given n locked boxes with keys inside, determine if all can be unlocked.

## 📋 Rules
- Box 0 starts unlocked
- Keys are box indices
- Return True if all accessible, False otherwise

## 🧠 Algorithm
Breadth-first search with queue-based traversal.

## 💡 Examples

### ✅ All unlockable
```python
boxes = [[1], [2], [3], []]
result = canUnlockAll(boxes)  # True
```

### ❌ Some unreachable
```python
boxes = [[1, 4, 6], [2], [0, 0, 0], [3, 1], [2], [4, 1], [5, 6]]
result = canUnlockAll(boxes)  # False
```

## 🚀 Usage
```bash
python3 0-lockboxes.py
```

## ⚡ Performance
- **Time**: O(n + k)
- **Space**: O(n)

---
🧮 **BFS Algorithm** • 🐍 **Python 3**
