class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string output{strs[0]};
        for (auto i = 1; i < strs.size(); ++i) {
            auto j = 0;
            for (; j < output.length() && j < strs[i].length(); ++j) {
                if (output[j] != strs[i][j]) break;
            }
            if (j <= strs[i].length()) output.resize(j);
        }
        return output;
    }
};

