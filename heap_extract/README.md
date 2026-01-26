# Heap Extract

Function that extracts the root node of a Max Binary Heap.

## Description

The `heap_extract` function extracts the root node (maximum value) from a Max Binary Heap, replaces it with the last level-order node, and rebuilds the heap if necessary to maintain the max heap property.

## Prototype

```c
int heap_extract(heap_t **root);
```

## Parameters

- `root`: Double pointer to the root node of the heap

## Return Value

- Returns the value stored in the root node
- Returns `0` if the function fails (e.g., root is NULL or heap is empty)

## Algorithm

1. Store the root node's value
2. If the heap has only one node, free it and return the value
3. Find the last level-order node in the heap
4. Replace the root's value with the last node's value
5. Remove the last node from the heap
6. Call `heapify_down` to restore the max heap property
7. Return the original root value

## Requirements

- The root node must be freed and replaced with the last level-order node
- The heap must be rebuilt if necessary to maintain max heap property
- If the function fails, return 0
