# Problem

https://leetcode.com/problems/unique-binary-search-trees/

# Explanation

This problem is a classic recurrence relation. The number of binary search trees for `n` (let's call it `nt(n)` can easily be expressed in terms of the number of binary search trees for values less than `n`. It's just a matter of figuring out the relationship.

The base cases for the recurrence are the values 0 and 1, where the number of possible tree configurations should be fairly obvious. My implementation adds 2 to the base cases as an optimization because, as it turns out, the answer to `nt(n)` for `n` in range  [0, 2] is `n`. So while 2 is not strictly speaking a base case, it fits the base case pattern neatly enough.

The first interesting case is 3, but it doesn't exemplify all the possibilities. My explanation will skip ahead to 5. Sketching out the possibilities, it becomes clear that you need to pick a root and see what happens underneath it.

* With 1 as the root, you essentially get the number of possible binary search trees for 4. The same goes for 5 as the root. There is a symmetry present in the calculation. We start with `2 * nt(4)`.
* With 2 as the root, you get the number of possible binary search trees for 3 on one side and 1 on the other. The symmetry persists. So you add `2 * nt(3) * nt(1)`.
* With 3 as the root, we reach a balancing point because `n` is odd and there is an exact middle. If we multiply by 2 here, it would be counting the same configurations twice, but we still need to add `nt(2) * nt(2)`

If we increase the value of `n` a bit more, we realize that the middle step is actually a loop that iterates `floor(n / 2)` times, and the third step only happens for odd numbers.

Now everything is nice and neat and we can get the correct answer every time. But it's just not very efficient because we calculate the same things over and over unnecessarily. So we keep track of the answers to shortcut the calculation, which of course is known as memoization and is the recursive form of the dynamic programming technique.

