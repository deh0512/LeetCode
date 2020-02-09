# Problem 

https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

# Explanation

Binary search is the first thing to come to mind searching a sorted array, particularly since the description mentions O(log n) time.

My first slightly naive attempt searches for the insert positions of (target - 1) and (target + 1) to narrow down the position of target. This works nicely and gets accepted. However, in the worst case the implementation has linear time complexity because there are loops to find the target boundaries. It doesn't satisfy the requirements of the problem as implemented (see [the first code example](code1.cpp)).

I realized that searching for the insert positions of (target + 1) and (target - 1) doesn't have any great advantages over just searching for the target. The loops to find the boundaries could as easily have gone outward from the target as inward from the surrounding values. So that approach was clearly not correct.

Instead, we can search for the target itself, and then continue to search in the partitions until the target is no longer found (see [the second code example](code2.cpp)). This approach is, I believe, actually O(log^2 n) time complexity, since it's essentially doing a binary search inside a binary search. It is the closest thing I can come up with that might be mistaken for O(log n), and the [cppreference](https://en.cppreference.com/w/cpp/algorithm/equal_range) documentation for C++'s `equal_range` function, which is basically this same algorithm, states that the average number of comparisons is 2 * log^2 n + 1.

