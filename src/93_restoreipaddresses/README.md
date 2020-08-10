# Problem

https://leetcode.com/problems/restore-ip-addresses/

# Explanation

This is a recursive backtracking search for valid IP addresses in the input string.

However, I believe this problem either isn't described well or the code that checks answers is wrong. It is valid for the string version of an IP to have leading zeros in its parts, but that is not accepted.

For instance, the input "2552051151" gets parsed into ["255.20.51.151","255.205.1.151","255.205.11.51","255.205.115.1"] by the checking algorithm, but "25.52.051.151" and "255.2.051.151" should also be acceptable.

