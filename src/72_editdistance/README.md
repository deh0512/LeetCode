# Problem

https://leetcode.com/problems/edit-distance/

# Explanation

This is yet another dynamic programming problem. I think it is more easily interpretable using the iterative model as opposed to recursion.

Essentially there is an integer state that is being optimized while traversing two words. Given iterators `i` and `j` across the input word and the target word respectively, `i` can be thought of as the number of letters used from the input, and `j` can be thought of as the length of the current solution. Moving right (increasing `j`) represents insertion. Moving down (increasing `i`) represents deletion. Moving diagonally (increasing both `i` and `j`) represents replacement. Then it's just a matter of calculating the minimum weight path to each cell. The solution is the last cell.

Both space and time complexity are O(m * n), where m and n are the lengths of the two words.

This problem seemed familiar (like something covered in a class some years ago), so I decided to do a bit of research. This variation of the edit distance problem is called the [Levenshtein distance](https://en.wikipedia.org/wiki/Levenshtein_distance). In some sense, it is a generalization of the [Hamming distance](https://en.wikipedia.org/wiki/Hamming_distance) for strings of unequal length.

