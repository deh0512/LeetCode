class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() < 2) return s.length();
        unordered_map<char, int> seen{};
        auto start = 0;
        auto i = 0;
        auto greatest = -1;
        for (; i < s.length(); ++i) {
            auto c = seen.find(s[i]);
            if (c != seen.end() && (*c).second >= start) {
                auto temp = i - start;
                if (temp > greatest) greatest = temp;
                start = (*c).second + 1;
            }
            seen[s[i]] = i;
        }
        if (i == s.length()) {
            auto temp = i - start;
            if (temp > greatest) greatest = temp;
        }
        return greatest;
    }
};

