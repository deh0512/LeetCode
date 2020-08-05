# Problem

https://leetcode.com/problems/gray-code/

# Explanation

The fact that the problem description involves altering bits one at a time immediately made me think the solution involved some bit manipulation operation, particularly exclusive-or. I latched on to that idea early in the process of solving this problem.

I laid out the gray code sequence with an input of 4 to get an idea what the pattern might be. Then I added some other columns to my representation so that I could see what each successive value would need to be exclusive-or'd with to arrive at the next value.

```
00000   0
00001   1   0^1    1  0001
00011   3   1^2    2  0010
00010   2   3^1    3  0001
00110   6   2^4    4  0100
00111   7   6^1    5  0001
00101   5   7^2    6  0010
00100   4   5^1    7  0001
01100  12   4^8    8  1000
01101  13  12^1    9  0001
01111  15  13^2   10  0010
01110  14  15^1   11  0001
01010  10  14^4   12  0100
01011  11  10^1   13  0001
01001   9  11^2   14  0010
01000   8   9^1   15  0001
```

I then thought about how to achieve the pattern that made up the exclusive-or right operands: `1 2 1 4 1 2 1 8 1 2 1 4 1 2 1`. It looks something like a tree of bits (or powers of 2) that's been squished. I realized that the placement of each value expands out from the center inversely according to its degree, and you can build up the list by starting with the largest relevant power of 3 value and just filling in the surrounding values at each level. As you decrease the value you are adding, you add it in more places on each side of the larger values.

Once you have the list with the appropriate pattern, it's just a matter of repeatedly exclusive-or'ing successive values the right number of times.

According to the statistics upon submission, this isn't quite the fastest possible way to arrive at the solution, but it shouldn't be far off.

