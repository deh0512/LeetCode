class Solution {
public:
    string countAndSay(int n) {
        if (n < 1) return "1";
        return countAndSay(n - 1, "1");
    }
    
private:
    string countAndSay(int n, const string& cur) {
        if (n == 0) return cur;
        stringstream ss{};
        auto i = 0;
        auto last = cur[i];
        auto cnt = 1;
        for (i = 1; i < cur.length(); ++i) {
            if (cur[i] != last) {
                ss << cnt << cur[i - 1];
                last = cur[i];
                cnt = 1;
            }
            else ++cnt;
        }
        ss << cnt << cur[i - 1];
        return countAndSay(n - 1, ss.str());
    }
};

