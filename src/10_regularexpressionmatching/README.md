# Problem

https://leetcode.com/problems/regular-expression-matching/

# Explanation

This one was quite frustrating for me, although not because the problem is particularly hard. I knew going into it that the solution is a dynamic programming solution since I have done subsets of regular expression problems before. Backtracking is the only way to get around the conditional character problem, and the subproblems of matching the tail end of the input string will happen repeatedly. Even knowing what the solution should look like, I kept stumbling on carelss mistakes. The two real catches to the problem itself are the need to continue searching even after the length of the input string is reached in case * characters follow the last match in the pattern, and the algorithm is incredibly more efficient if the final if statement first checks for the exact match or . before recursing.

