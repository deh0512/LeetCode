# Problem

https://leetcode.com/problems/interleaving-string/

# Explanation

The first inclination is to solve this as a [simple recursive DFS](code1.cpp) because backtracking is obviously necessary. That fails because the time limit is exceeded. So a more efficient solution exists.

The next thought is that [memoization](code2.cpp) seems natural. It's a dynamic programming problem after all.

Then there is an [iterative approach](code3.cpp) with a table that is even faster.

