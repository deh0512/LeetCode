# Problem

https://leetcode.com/problems/jump-game-ii/

# Explanation

This one psyched me out a bit. The solution is fairly simple, but the time constraints on acceptance require a subtle optimization to be present. Either that, or I don't have the algorithm quite right.

At any rate, what I have implemented is a dynamic programming solution such that it keeps track of the minimum number of hops from each previously searched location in the input array so that it can avoid recalculating. This alone makes it reasonably efficient. The optimization I mentioned is that it is possible to know whether you can possibly hop to the end in one or two hops from the current location, and if you hit that possible minimum number early you can just stop searching at that point. It makes sense, but it isn't obvious an optimization like that should be included in an otherwise very standard DP problem.

