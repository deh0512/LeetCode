# Problem

https://leetcode.com/problems/next-permutation/

# Explanation

The general idea is that the next lexicographical ordering will involve the first index where elements decrease when traversing in reverse order. If such an index is found, it needs to be swapped with the the first value from the tail that is larger than the element at that index. It is certain that such a value exists in the tail since it is already established that at least the element at the next index is larger. Once that is done, the elements in the rest of the vector need to be sorted or reversed. Sorting and reversing are equivalent in this case since it has been established that the tail is monotonically increasing.

This one took me probably longer than it should to fully understand. Sorting the tail seemed to have an inherent connection to what the outcome should look like, and I recognized that fairly early. I was a bit stuck figuring out which value from the tail should be swapped or maybe removed and inserted at the position where `i` is less than `i + 1`. The solution is deceptively simple.

