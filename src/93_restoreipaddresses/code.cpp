class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        auto output = vector<string>{};
        auto input = stringstream{s};
        auto currentIp = stringstream{};
        searchIp(output, input, currentIp, 0, 0l, 0, s.length());
        return output;
    }
    
private:
    inline bool correctDigitCount(int32_t digitCount, int32_t value) {
        return digitCount < 4 &&
               ((digitCount  == 3 && value >= 100) ||
                (digitCount == 2 && value >= 10) ||
                digitCount == 1);
    }
    
    void searchIp(
        vector<string>& output,
        stringstream& input,
        stringstream& currentIp,
        int32_t currentInt,
        int64_t currentDigitCount,
        int32_t parts,
        int32_t remainingDigits) {
        if (remainingDigits == 0) {
            if (parts + 1 == 4 && currentInt < 256 &&
                correctDigitCount(currentDigitCount, currentInt)) {
                currentIp << currentInt;
                output.push_back(currentIp.str());
                currentIp.seekp(currentIp.tellp() - currentDigitCount);
            }
            return;
        }
        auto digit = input.peek() - '0';
        auto newInt = (currentInt * 10) + digit;
        auto newRemainingDigits = remainingDigits - 1;
        if (newInt < 256) {
            auto ch = input.get();
            auto newDigitCount = currentDigitCount + 1l;
            if (newRemainingDigits / (4.0f - parts - 1.0f) <= 3.0f &&
                correctDigitCount(newDigitCount, newInt)) {
                currentIp << newInt << '.';
                searchIp(output, input, currentIp, 0, 0, parts + 1, newRemainingDigits);
                currentIp.seekp(currentIp.tellp() - (newDigitCount + 1l));
            }
            searchIp(output, input, currentIp, newInt, newDigitCount, parts, newRemainingDigits);
            input.putback(ch);
        }
    }
};

