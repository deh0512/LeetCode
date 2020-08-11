# Problem

https://leetcode.com/problems/merge-sorted-array/

# Explanation

In C++, it's easier to just use iterators, but the concept is the same if indices were used.

The first implementation is the naive version. Move through the two arrays from start to finish inserting into the first array whenever the item from the second array is less than the item from the first array. An optimization to this implementation would be to process chunks in order to minimize the sliding over operation inherent in inserting into an array. If this sort of thing were going to happen in production code, it might also be reasonable to consider using a list for storage, where inserts are more efficient.

The second implementation is a bit more clever. It uses three reverse iterators, one to keep track of where the next value is being stored in the first array and the other two to move through the values. Going in reverse ensures there's no need to slide things over, which makes the whole algorithm linear instead of `O(n^2)` like the first implementation. While this is a big difference in asymptotic complexity, the test cases from LeetCode must be sufficiently small that there is no practical difference in execution time. Oh well, I tried.

