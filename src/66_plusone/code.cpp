class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty()) return digits;
        auto n = static_cast<int>(digits.size());
        digits[n - 1] += 1;
        auto carry = digits[n - 1] / 10;
        digits[n - 1] %= 10;
        for (auto i = n - 2; i >= 0; --i) {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
            if (carry == 0) break;
        }
        if (carry > 0) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};

