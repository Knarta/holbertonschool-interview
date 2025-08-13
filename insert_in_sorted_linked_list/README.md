# 📚 Insert in Sorted Linked List

## 📝 Description

C function that inserts a number into a sorted singly linked list, maintaining the ascending order of elements.

## 🔧 Prototype

```c
listint_t *insert_node(listint_t **head, int number);
```

## 📥 Parameters

- `head` : Pointer to the pointer of the list head
- `number` : Number to insert

## 📤 Return

- Address of the new node created
- `NULL` on failure

## 🚀 Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic 0-main.c linked_lists.c 0-insert_number.c -o insert
```

## ▶️ Execution

```bash
./insert
```

## 🧪 Test

The program tests the insertion of number 27 into a sorted list:
- Initial list: 0, 1, 2, 3, 4, 98, 402, 1024
- After insertion: 0, 1, 2, 3, 4, 27, 98, 402, 1024

## ⚠️ Constraints

- No Google search allowed
- Whiteboard first
- Pure C implementation