class Solution {
public:
    bool isValid(string s) {
        deque<char> stack{};
        for (char c : s) {
            if (openers.find(c) != openers.end()) {
                stack.push_back(c);
            }
            else {
                auto close = closers.find(c);
                if (close != closers.end()) {
                    if (stack.empty() || (*close).second != stack.back()) {
                        return false;
                    }
                    stack.pop_back();
                }
            }
        }
        return stack.empty();
    }

private:
    unordered_set<char> openers{'(', '{', '['};
    unordered_map<char, char> closers{
        {')', '('},
        {']', '['},
        {'}', '{'}
    };
};

