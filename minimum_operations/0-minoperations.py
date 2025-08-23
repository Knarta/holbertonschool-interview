#!/usr/bin/python3
"""
Method that calculates the fewest number of operations needed to
 result in exactly n H characters in the file.

operation_needed : count operations
clipboard: store currentclipboard contents
current_length: track the current length of the string

"""


def minOperations(n):

    if n <= 1:
        return 0

    operation_needed = 0
    clipboard = 0
    current_length = 1

    while current_length < n:
        if n % current_length == 0 and current_length * 2 <= n:
            # copy current string to clipboard
            clipboard = current_length
            operation_needed += 1
        else:
            # paste clipboard content
            if clipboard > 0:
                current_length += clipboard
                operation_needed += 1
            else:
                # no clipboard content, add one character
                current_length += 1
                operation_needed += 1

    return operation_needed
