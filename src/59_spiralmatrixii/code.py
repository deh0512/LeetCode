class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        if n <= 0:
            return []
        total = n ** 2
        output = [[0 for _ in range(n)] for _ in range(n)]
        s = i = j = 0
        d = 'r'
        l = b = n - 1
        r = t = 0
        while s < total:
            output[i][j] = s + 1
            if d == 'r':
                j += 1
                if j == l:
                    d = 'd'
                    t += 1
            elif d == 'd':
                i += 1
                if i == b:
                    d = 'l'
                    l -= 1
            elif d == 'l':
                j -= 1
                if j == r:
                    d = 'u'
                    b -= 1
            elif d == 'u':
                i -= 1
                if i == t:
                    d = 'r'
                    r += 1
            s += 1
        return output

