# Problem

https://leetcode.com/problems/valid-sudoku/

# Explanation

There are 9 rows, 9 columns, and 9 boxes. There are 9 possible values that must be unique within each. To tell if a given board is valid, it is just necessary to tabulate the possibilities and traverse the entire board making sure no value shows up more than once in a row, column, or box. Since the size of the board is known, I suppose it's arguable that the time and space complexity are constant, but it's probably more accurate to say both are O(n) where n is the size of the board.

