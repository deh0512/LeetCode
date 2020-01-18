# Problem

https://leetcode.com/problems/two-sum/

# Explanation

I have seen this problem in practice interviews on YouTube before, so it doesn't surprise me that it's the first example on LeetCode.

The trick is to remember numbers that have been seen while stepping through the input because determining a match is simple subtraction. Use a map to recall the index of the match. Both time and space complexity are O(n).

