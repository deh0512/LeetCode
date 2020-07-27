# Problem

https://leetcode.com/problems/first-missing-positive/

# Explanation

This one is a little tricky only because of the requriement for linear time complexity and constant _extra_ space. Otherwise, you could just sort them and be done with it.

I started thinking about whether it helps to know the smallest value in the original array or whether there is some trick with summing values in the array that are greater than zero. I considered whether there might be some statistical property of the array that could be helpful like the average or median. None of these make sense, though, because inevitably too much information is lost when you condense the array down to some representative values.

The key insight for me was when I paid more attention to the unusual wording of the problem. It says constant "extra" space, meaning it's ok to use the original array as storage while solving the problem. Combine that with the insight that the answer necessarily is a value between 1 and the size of the array plus 1, and a solution begins to take shape. You can use a first pass through the array to swap values into their correct places and a second pass to check what value is missing. There is a little bit of special care needed to deal with duplicate values and the case where you swap a value that itself also needs to be swapped. Basically the first loop is a little funny because you need to either swap or move forward, not both. But it's fairly straightforward at this point.

