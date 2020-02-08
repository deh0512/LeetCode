# Problem

https://leetcode.com/problems/merge-k-sorted-lists/

# Explanation

The first code example is a naive solution. The execution time is not optimal because it traverses the sorted list each time a new list is merged in. There are a number of edge cases to pay attention to, but it's not too difficult to follow. The naive solution gets accepted, so I have included it. The fact that about 75% of solutions are faster than this suggested there is a better solution.

The better solution is to use a structure that can insert elements without traversing the entire output list each time. A tree-based structure could reduce the insertion time to O(log n). A priority queue fits the use-case. It reduces the code complexity and execution time significantly.

