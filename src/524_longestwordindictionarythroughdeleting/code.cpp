class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string longest{};
        for (auto& dword : d) {
            if (dword.length() > s.length()) continue;
            auto i = 0, j = 0;
            while (i < dword.length() && j < s.length()) {
                if (dword[i] == s[j]) {
                    ++i;
                    ++j;
                }
                else ++j;
            }
            if (i == dword.length() &&
                (dword.length() > longest.length() ||
                 (dword.length() == longest.length() && dword < longest))) longest = dword;
        }
        return longest;
    }
};

