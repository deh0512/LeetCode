# Problem

https://leetcode.com/problems/sudoku-solver/

# Explanation

Solving a Sudoku puzzle is considerably more complex than validating a board ([#36](../36_validsudoku)). There is no simple formulaic solution, so a generalized algorithm will require backtracking. It's a pretty standard dynamic programming problem. Like many similar problems, interpreting the board (or matrix) as a graph and applying depth-first search with memoization yields a correct solution.

