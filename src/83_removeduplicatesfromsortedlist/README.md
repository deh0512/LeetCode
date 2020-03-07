# Problem

https://leetcode.com/problems/remove-duplicates-from-sorted-list/

# Explanation

Since the list is sorted, duplicates will be next to each other. It's just a matter of comparing successive values and stitching the list together where values are not equal.

The outer loop iterates over nodes with different values. The inner loop iterates over duplicates. Each node is visitied only once, so the time complexity is still linear.

