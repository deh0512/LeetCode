class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        permutations = math.factorial(m + n - 2)
        return int(permutations / (math.factorial(m - 1) * math.factorial(n - 1)))

