// Nice simple solution, but exceeds time limit when submitted... :(
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size() != s1.size() + s2.size()) return false;
        return dfs(s1, s2, s3, 0, 0, 0);
    }
    
private:
    bool dfs(string_view s1, string_view s2, string_view s3, int i, int j, int k) {
        if (k == s3.size()) return true;
        if (s3[k] == s1[i]) {
            if (dfs(s1, s2, s3, i + 1, j, k + 1)) return true;
        }
        if (s3[k] == s2[j]) {
            if (dfs(s1, s2, s3, i, j + 1, k + 1)) return true;
        }
        return false;
    }
};

