# Problem

https://leetcode.com/problems/simplify-path/

# Explanation

There is nothing tricky about this problem. It can be done in a number of ways, all just simple iterations over the input string split on the forward slash character (`'/'`). I tried a number of variations to find the fastest version. As it turns out, the versions that use a list comprehension to implement the simpler parts of the logic are quite slow.

