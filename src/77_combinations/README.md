# Problem

https://leetcode.com/problems/combinations/

# Explanation

This only requires a simple for-loop and recursion. The time complexity is exactly `n choose k` since we are building the number of combinations. So that's `n! / (k! * (n - k)!)`, which is approximately `O(n^k)`. You arrive at that first by factoring out `1 / k!` as a constant. Then, being left with `n! / (n - k)!`, we are basically looking at `n * (n - 1) * (n - 2) * ... * (n - k + 1)`. That is `n` multiplied by itself approximately `k` times, or `n^k`, as far as asymptotic complexity is concerned.

