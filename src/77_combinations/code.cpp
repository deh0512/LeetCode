class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        auto output = vector<vector<int>>{};
        auto current = vector<int>{};
        current.reserve(k);
        search(output, current, n, k, 1);
        return output;
    }
    
private:
    void search(vector<vector<int>>& output, vector<int>& current, int n, int k, int i) {
        if (current.size() == k) {
            output.push_back(current);
            return;
        }
        auto diff = k - current.size() - 1;
        for (auto x = i; x <= n - diff; ++x) {
            current.push_back(x);
            search(output, current, n, k, x + 1);
            current.pop_back();
        }
    }
};

