# Problem

https://leetcode.com/problems/powx-n/

# Explanation

The simplest solution is just to multiply by _x_ _n_ times. There's a logarithmic time solution where you multiply larger multiples together. For example, 3^4 = 81, but it's simple to see that you can multiply once (3 * 3 = 9) and then multiply that times itself (9 * 9 = 81) to achieve the same result. Basically, using _x * x_ you can divide the exponent in half. You can do that recursively to drastically reduce the time it takes to exponentiate by larger values.

There are a couple of little gotchas in this problem. First, you have to deal with negative exponents, which means there are two paths to the logic. Second, if you deal with negative exponents in the simplest way possible, which is to use the definition and return 1.0 divided by the result of exponentiating _x_ by _-n_, then there is an edge case due to flipping the sign of _n_. There is one more negative integer expressable in 32 bits than there are positive integers. Casting to a _long_ in the internal logic is a very basic way to solve this problem.

