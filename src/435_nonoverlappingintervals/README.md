# Problem

https://leetcode.com/problems/non-overlapping-intervals/

# Explanation

This is just the scheduling problem from algorithm textbooks. The solution is a greedy algorithm. If an interval fits, use it. That simple manifestation fails on anything more than the examples in the description because the inputs aren't always presented in an optimal order. But if the input were sorted, it might work better. A regular sort, which would sort by each element in turn for vectors and effectively by the start value in this case, doesn't yield an optimal result. The trick is to sort by the end value instead.

