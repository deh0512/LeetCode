class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.empty() || num2.empty()) return "";
        if (num1.length() >= num2.length()) return multiplyForReal(num1, num2);
        return multiplyForReal(num2, num1);
    }
    
private:
    string multiplyForReal(string num1, string num2) {
        vector<string> intermediates{};
        stringstream ss{};
        auto carry = 0;
        for (int j = num2.length() - 1; j >= 0; --j) {
            ss.clear();
            ss.seekp(0);
            carry = 0;
            for (auto i = 0; i < num2.length() - j - 1; ++i) ss << '0';
            for (int i = num1.length() - 1; i >= 0; --i) {
                auto d = carry + (num1[i] - '0') * (num2[j] - '0');
                carry = d / 10;
                ss << (d % 10);
            }
            if (carry) ss << carry;
            intermediates.push_back(ss.str());
        }
        ss.clear();
        ss.seekp(0);
        carry = 0;
        auto l = intermediates[intermediates.size() - 1].length();
        for (auto i = 0; i < l; ++i) {
            auto d = carry;
            for (auto j = 0; j < intermediates.size(); ++j)
                if (i < intermediates[j].size()) d += intermediates[j][i] - '0';
            carry = d / 10;
            ss << (d % 10);
        }
        if (carry) ss << carry;
        else --l;
        ss.seekg(l);
        while (l > 0 && ss.peek() == '0') ss.seekg(--l);
        ss.seekg(0);
        auto temp = ss.str().substr(0, l + 1);
        return string{temp.rbegin(), temp.rend()};
    }
};

