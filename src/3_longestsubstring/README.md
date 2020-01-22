# Problem

https://leetcode.com/problems/longest-substring-without-repeating-characters/

# Explanation

This problem isn't as simple as I first thought, but it's not too terribly complex in the end. It doesn't require 2 for loops. You need to remember the index at which you've seen a duplicated character before to adjust the current state accordingly and keep moving through the string. My [original thought](code1.cpp) was to use a map to do this, but I realized later that it can be [done more efficiently with an integer array](code2.cpp) with the characters treated as indices.

I had the unfortunate realization that LeetCode apparently doesn't use the same setup for "Run Code" as it does for "Submit" with this problem. I submitted code that I believe should have worked and actually did work when run via "Run Code" and the experimental debugger, but it failed repeatedly during submission. That brings my submission stats down a bit, but oh well... :)

