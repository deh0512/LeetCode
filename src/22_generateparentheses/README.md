# Problem

https://leetcode.com/problems/generate-parentheses/

# Explanation

I really wanted an iterative solution for this one, but it escaped me. I also tried some solutions using stringstream instead of string to build the values, but it turns out that's considerably slower than just using string concatenation. That's counterintuitive from my experience with Java and StringBuilder, but it pays to profile. So it's just a basic recursive solution searching all the sensible possibilities.

