# 🔗 Linked List Palindrome Detection

> *Next-generation palindrome verification for singly linked lists*

## 🚀 Overview
A cutting-edge C implementation that determines whether a singly linked list forms a palindrome pattern. Built for optimal performance and memory efficiency in modern computing environments.

## 🎯 The Challenge Decoded

### What's a Palindrome?
A **palindrome** is a sequence that reads identically in both directions - a perfect symmetrical data pattern.

**Real-world Examples:**
- 📝 Words: `"radar"`, `"level"`, `"madam"`
- 🔢 Numbers: `121`, `1331`, `12321`
- 📊 Lists: `[1, 2, 3, 2, 1]` or `[1, 17, 972, 50, 98, 98, 50, 972, 17, 1]`

### The Technical Challenge

Your mission: Detect palindromes in **singly linked lists** with surgical precision.

**Data Structure Architecture:**
```c
typedef struct listint_s
{
    int n;                    // node payload
    struct listint_s *next;   // forward pointer
} listint_t;
```

### Live Example

Consider this linked list structure:
```
[1] ➜ [17] ➜ [972] ➜ [50] ➜ [98] ➜ [98] ➜ [50] ➜ [972] ➜ [17] ➜ [1] ➜ NULL
```

**✅ Palindrome Confirmed** because:
- 1st element (1) ↔ 10th element (1)
- 2nd element (17) ↔ 9th element (17)
- 3rd element (972) ↔ 8th element (972)
- Perfect symmetry achieved

### Core Engineering Challenges

1. **🔄 Unidirectional Access**: Unlike arrays, linked lists only allow forward traversal
2. **⚡ No Random Access**: Direct element indexing is impossible
3. **💾 Memory Constraints**: Must avoid excessive auxiliary space usage
4. **🎯 Preservation**: Original list structure must remain intact

### Advanced Algorithm Strategy

Our high-performance solution employs:

1. **🐢🐰 Two-Pointer Technique**: Find the middle using "tortoise and hare" algorithm
2. **🔀 Strategic Reversal**: Reverse the second half of the list
3. **⚖️ Symmetric Comparison**: Compare both halves element by element
4. **🔧 Structure Restoration**: Rebuild original list architecture

### Edge Case Mastery

- **∅ Empty List**: Inherently palindromic (returns `1`)
- **• Single Node**: Always palindromic (returns `1`)
- **⚡ Even/Odd Length**: Algorithm handles both scenarios seamlessly

### Performance Metrics

- **⏱️ Time Complexity**: `O(n)` - single-pass efficiency
- **💾 Space Complexity**: `O(1)` - constant memory footprint
- **🎯 Optimization Level**: Enterprise-grade performance

## 🛠️ Technical Requirements

### Development Environment
- **💻 Editors**: `vi`, `vim`, `emacs`
- **🐧 Platform**: Ubuntu 14.04 LTS
- **⚙️ Compiler**: GCC 4.8.4 with strict flags: `-Wall -Werror -Wextra -pedantic`
- **📏 Code Style**: Betty standard (validated via betty-style.pl & betty-doc.pl)

### Code Standards
- ✅ All files must end with a newline
- 🚫 No global variables allowed
- 📦 Maximum 5 functions per file
- 📋 Function prototypes in `lists.h` header
- 🛡️ Include guards mandatory for all headers

## 🎯 Mission Brief

### Task 0: Palindrome Detection Engine

**Objective**: Engineer a function that detects palindromic patterns in singly linked lists.

**Function Signature**: 
```c
int is_palindrome(listint_t **head);
```

**Return Values**:
- `0` ➜ Not a palindrome
- `1` ➜ Palindrome detected
- Empty lists are considered palindromic by default

## 📁 Project Architecture

```
linked_list_palindrome/
├── 0-is_palindrome.c    # Core palindrome detection logic
├── lists.h              # Function prototypes & data structures
├── linked_lists.c       # Utility functions (provided)
└── 0-main.c            # Test harness (example)
```

## ⚡ Build & Deploy

### Compilation Command
```bash
gcc -Wall -Werror -Wextra -pedantic 0-main.c linked_lists.c 0-is_palindrome.c -o palindrome
```

### Execution
```bash
./palindrome
```

### Expected Output
```
1
17
972
50
98
98
50
972
17
1
Linked list is a palindrome
```

## 📊 Repository Info
- **🏢 Organization**: `holbertonschool-interview`
- **📂 Directory**: `linked_list_palindrome`
- **📄 Deliverables**: `0-is_palindrome.c`, `lists.h`

---
*Built with precision engineering for modern data structure challenges*
