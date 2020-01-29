class Solution {
public:
    string intToRoman(int num) {
        static const list<pair<int, string>> roman{
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };
        stringstream ss{};
        for (auto const& [div, str] : roman) {
            auto x = num / div;
            num %= div;
            for (auto i = 0; i < x; ++i) ss << str;
        }
        return ss.str();
    }
};

