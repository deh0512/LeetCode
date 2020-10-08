# Problem

https://leetcode.com/problems/knight-dialer/

# Explanation

This is a pretty standard dynamic programming problem. The amount of space needed can be minimized by just keeping track of the previous values instead of an entire table. The spatial complexity is `O(n)`. The time complexity if also linearsince the amount of work is at most a constant value (30) at each hop, and the number of hops is determined by `n`.

