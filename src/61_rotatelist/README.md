# Problem

https://leetcode.com/problems/rotate-list/

# Explanation

Using multiple pointers is the key to efficiency in this problem. Most of the edge cases are straightforward, although I didn't catch them all the first couple of tries. Having only a single node or when _k_ is the length of the list means the return value is the same as the input list. The trickiest thing is when _k_ is very large, there's no need to cycle through the list a bunch of times. You can adjust _k_ modulo the length of the list once the length of the list is known.

