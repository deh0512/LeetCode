# Problem

https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

# Explanation

The naive solution is to use two for loops and keep doing the subtraction over and over. This would be O(n^2). A bit smarter way to do it is to realize that if you loop through the input backwards and remember the largest value you've seen so far, the maximum difference can be determined in a single traversal.

