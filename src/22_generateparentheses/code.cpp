class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> parens{};
        search(parens, "", n, 0, 0);
        return parens;
    }
    
private:
    void search(vector<string>& output, string s, int n, int i, int j) {
        if (i > n || j > n) return;
        if (i == n && j == n) {
            output.emplace_back(s);
            return;
        }
        if (i == j) {
            search(output, s + "(", n, i + 1, j);
        }
        else {
            search(output, s + "(", n, i + 1, j);
            search(output, s + ")", n, i, j + 1);
        }
    }
};

