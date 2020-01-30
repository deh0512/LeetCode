# Problem

https://leetcode.com/problems/divide-two-integers/

# Explanation

There is probably some elegant solution to this one that doesn't involve so much explicit handling of corner cases, but the acceptance rate leads me to believe that most people don't know it. It took me a number of times to get an accepted answer despite thinking it would be quite simple at the beginning. The solution I arrived at is somewhat convoluted, but relatively efficient. In some sense it is cheating to use shift operators since that is the same as multiplying by two, but the performance constraints on the test cases would be far too stringent otherwise.

One trick is to use absolute values to avoid a bunch of if statements. There is an edge case to be handled in that the minimum value of a 32 bit integer will overflow if you take the absolute value of it.

The main algorithm is to shift left until the divisor value is as large as it can be without being larger than the dividend. Similarly shift the increment/decrement value (called step in the code). Repeatedly subtract the multiple of the divisor from the dividend and add the multiple of the step value to the quotient. When you can't do that anymore (it should be possible to do at most twice for each shifted value of the divisor), then shift both the divisor and step values to the right. Once that's been done with the original divisor and a step value of 1, the quotient will be correct.

This problem also made me realize how ridiculous the "faster than <whatever>%" execution time assessments are. The exact same solution is apparently faster 26%, 73%, and 100% depending on when it gets submitted. Execution times seem to be measured in increments of 4ms near the low end (so 0ms, 4ms, 8ms, 12ms), and if a solution is somewhere in this range the comparison with other solutions in this range is nearly meaningless.

