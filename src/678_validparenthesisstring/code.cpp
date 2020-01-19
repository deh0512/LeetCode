class Solution {
public:
    bool checkValidString(string s) {
        if (s.empty()) return true;
        deque<char> stack{};
        auto stars = 0;
        for (auto c : s) {
            if (c == ')') {
                auto found = false;
                while (!stack.empty()) {
                    auto o = stack.back();
                    stack.pop_back();
                    if (o == '(') {
                        found = true;
                        break;
                    }
                    ++stars;
                }
                if (!found) {
                    if (stars == 0) return false;
                    --stars;
                }
            }
            else {
                for (auto i = 0; i < stars; ++i) stack.push_back('*');
                stars = 0;
                stack.push_back(c);
            }
        }
        while (!stack.empty()) {
            if (stack.back() == '(') {
                if (stars == 0) return false;
                --stars;
            }
            else ++stars;
            stack.pop_back();
        }
        return true;
    }
};

