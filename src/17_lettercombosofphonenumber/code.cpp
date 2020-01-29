class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        static const vector<vector<char>> letters{
            {},
            {},
            {'a', 'b', 'c'},
            {'d', 'e', 'f'},
            {'g', 'h', 'i'},
            {'j', 'k', 'l'},
            {'m', 'n', 'o'},
            {'p', 'q', 'r', 's'},
            {'t', 'u', 'v'},
            {'w', 'x', 'y', 'z'},
        };
        auto combos = 1l;
        for (auto i = 0; i < digits.length(); ++i) {
            auto d = static_cast<int>(digits[i] - '0');
            combos *= letters[d].size();
        }
        vector<stringstream> temp{combos};
        auto cycle = combos;
        for (auto i = 0; i < digits.length(); ++i) {
            auto d = static_cast<int>(digits[i] - '0');
            const auto& ls = letters[d];
            auto lsz = ls.size();
            cycle /= lsz;
            for (auto j = 0l; j < combos; ++j) {
                int ci = (j / cycle) % lsz;
                temp[j] << ls[ci];
            }
        }
        vector<string> output{};
        output.reserve(combos);
        for (auto i = 0; i < combos; ++i) {
            output.push_back(temp[i].str());
        }
        return output;
    }
};

