class Solution:
    def simplifyPath(self, path: str) -> str:
        parts = [p for p in path.split('/') if p and p != '.']
        i = 0
        while i < len(parts):
            if parts[i] == '..':
                if i > 0:
                    del parts[i - 1]
                    i -= 1
                del parts[i]
            else:
                i += 1
        return '/' + '/'.join(parts)

