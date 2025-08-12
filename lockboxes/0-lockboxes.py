#!/usr/bin/python3
"""
Module for solving the lockboxes problem.
Determines if all boxes can be unlocked given keys in each box.
"""


def canUnlockAll(boxes):
    """
    Check if we can unlock all the boxes
    """
    if not boxes:
        return False

    n = len(boxes)
    unlocked_boxes = [False] * len(boxes)
    unlocked_boxes[0] = True  # first box is open

    keys = [0]  # start with first box

    while keys:
        box = keys.pop()
        for key in boxes[box]:
            if key < len(boxes) and not unlocked_boxes[key]:
                unlocked_boxes[key] = True
                keys.append(key)

    return all(unlocked_boxes)
