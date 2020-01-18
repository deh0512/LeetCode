# Problem

https://leetcode.com/problems/linked-list-cycle/

# Explanation

The [naive solution](code1.cpp) is straightforward.

The follow-up question about using constant space is a well-known trick for checking cycles in linked lists known as [fast-slow pointers](code2.cpp) (or something along those lines). The idea is that one pointer traverses consecutive nodes normally while another skips every other node. It is provable that the slow and fast pointers will eventually land on the same node (excluding the head the first time through the loop) if there is a loop.

