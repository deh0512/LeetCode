# Problem

https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

# Explanation

Create a vector each time you reach a new level. Push the current node's value onto the current level's vector. Visit left children first. Reverse the final output.

The most efficient way should be to do a breadth-first traversal and simply push a new vector to the front of the output at each new level. That would save the need to reverse things at the end, and just makes a bit more sense. I haven't implemented that yet, though...

