# Problem

https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/

# Explanation

This one is pretty straightforward. The only catch is that the "dictionary" isn't sorted in some of the validation tests. It can be sorted before the main loop, but it is more efficient to just add a comparison for lexicographic order in the determination for which longest match to return.

