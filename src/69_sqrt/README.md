# Problem

https://leetcode.com/problems/sqrtx/

# Explanation

This algorithm is a naive binary search to find the integral lower bound of the square root of a number. The time complexity is logarithmic since it is a binary search. The naivety limits the size of _x_ because there is a multiplication of _(x / 2) * (x / 2)_. When that value does not fit in a 64 bit integer, the whole thing blows up. Luckily, verification inputs never exceed that limit. Improvements on the algorithm might include choosing the starting maximum value of the search in a more clever way or using a big integer library to allow arbitray sized values in the problematic multiplication.

