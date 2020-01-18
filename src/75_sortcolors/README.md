# Problem

https://leetcode.com/problems/sort-colors/

# Explanation

The problem statement says to avoid the simple counting solution and that the desired solution is a single pass. Given those constraints, my first thought was to throw zeros to the front and twos to the back, which naively seems like it would work. The problem with that is how to terminate the loop once all the twos are at the back. You would just keep throwing the next two and never move forward. A minor modification to that idea yields a solution where the set of zeros is built up remembering the index of the first non-zero value, and the set of twos at the end is likewise built remembering the last non-two value. Using these indices as insert points when throwing zeros toward the front and twos toward the back yields an optimal one-pass solution.

