# Problem

https://leetcode.com/problems/unique-paths/

# Explanation

I honestly don't know what this is doing on a coding problem site. This is just a known mathematical equation for the number of permutations with repetitions.

I remembered the formula for permutations, which is `n! / (n - r)!`. In this case, with a grid `m` by `n`, the formula is just `(m + n - 2)!` because we need to move `m - 1` spaces to the right and `n - 1` spaces down and we are choosing all `m - n - 2` possible values so the denominator is 1.

I had to look it up, but to account for repetitions you just divide by the product of the factorial of each repeated item count. So in this case we divide by `(m - 1)! * (n - 1)!`.

EZPZ.

