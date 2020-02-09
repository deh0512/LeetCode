# Problem

https://leetcode.com/problems/remove-duplicates-from-sorted-array/

# Explanation

Loop through the array. Remember the position of the last unique number. When the next unique number is found, increment that position, increase the length, and, if it wasn't simply the next index, copy the new unique value to this newly incremented index.

