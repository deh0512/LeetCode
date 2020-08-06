class Solution:
    def simplifyPath(self, path: str) -> str:
        parts = [p for p in path.split('/') if p and p != '.']
        new_parts = []
        for p in parts:
            if p == '..':
                if new_parts:
                    new_parts.pop()
            else:
                new_parts.append(p)
        return '/' + '/'.join(new_parts)

