# Problem

https://leetcode.com/problems/count-number-of-nice-subarrays/

# Explanation

An initial naive approach might be to build a table whereby one axis represents the start index of the sub-array and the other axis represents the end index. The values would be the counts of odd numbers between the two indices. A table like that would have a lot of wasted space because start indices cannot be greater than end indices, meaning all the values on one side of the diagonal are meaningless. Furthermore, some number of rows (or columns, depending on which axis is which) should be meaningless if `k` is larger than 1.

Immediately, a solution presents itself that is the same time complexity as that first naive approach, but uses far less space. All those same calculations can be made in a single array with the same size as the `nums` input. [This implementation](code1.cpp) is not very efficient, though, and fails validation due to a timeout (assuming that's all that's wrong with it).

From here, it took a couple more iterations to pare it down to a [single loop and a map](code2.cpp). It is still based on the observation that all that matters are the counts of odd numbers, and it can be done in a single loop using a technique similar to using a prefix sum to solve sums of ranges.

