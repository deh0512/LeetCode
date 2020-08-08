# Problem

https://leetcode.com/problems/subsets-ii/

# Explanation

My first solution is a bit naive. During the course of testing the fact that answers could be wrong when the outputs weren't sorted betrayed that the code doing the checking is essentially incorrect and simultaneously hinted at the better solution. Also, the repetitive code (the for loop and use of a set to prevent duplication) also seemed suspect.

The second solution makes use of the sorted values to prevent duplication in a more efficient way and removes the code duplication. The asymptotic time complexity should be the same, O(n!), but the second version is way faster for all practical purposes. The extra work of maintaining a set to prevent recursing on the same value and finding whether the power set contains the current set eats up a lot of time.

