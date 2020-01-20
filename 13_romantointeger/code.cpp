class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> values{
            {' ', INT_MAX},
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        unordered_set<char> prefix{'I', 'X', 'C'};
        auto output = 0;
        auto last = ' ';
        for (auto i = 0; i < s.length(); ++i) {
            auto c = s[i];
            auto cur_val = values[c];
            auto last_val = values[last];
            if (cur_val > last_val) {
                if (prefix.find(last) == prefix.end()) {
                    return 0;
                }
                output -= 2 * last_val;
            }
            output += cur_val;
            last = c;
        }
        return output;
    }
};

