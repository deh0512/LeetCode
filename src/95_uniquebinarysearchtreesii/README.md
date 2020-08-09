# Problem

https://leetcode.com/problems/unique-binary-search-trees-ii/

# Explanation

There is a related discussion for the [counting version of this problem](../96_uniquebinarysearchtrees).

Instead of doing the math, this problem requires building the search trees during the course of the recursion. Basically, at each level, pick a root, split the values into smaller and larger sections, and recurse on each. Splitting things into groups is simple because the values are sorted.

Dynamic programming can help here as well, because there is an optimal substructure. The result of each subproblem can be reused.

