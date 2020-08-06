class Solution:
    def simplifyPath(self, path: str) -> str:
        new_parts = []
        for p in path.split('/'):
            if not p or p == '.':
                continue
            elif p == '..':
                if new_parts:
                    new_parts.pop()
            else:
                new_parts.append(p)
        return '/' + '/'.join(new_parts)

