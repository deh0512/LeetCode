class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<char, int> smap{};
        unordered_map<char, int> tmap{};
        for (auto i = 0; i < s.length(); ++i) {
            ++smap[s[i]];
            ++tmap[t[i]];
        }
        return smap == tmap;
    }
};

