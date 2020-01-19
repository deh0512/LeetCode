class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), [](const auto& v1, const auto& v2) {
            return v1[1] < v2[1];
        });
        vector<vector<int>> use{};
        use.reserve(intervals.size());
        auto remove = 0;
        for (auto& intvl : intervals) {
            auto take = true;
            for (auto& used : use) {
                if (intvl[0] < used[1] && intvl[1] > used[0]) {
                    take = false;
                    break;
                }
            }
            if (take) use.push_back(intvl);
            else ++remove;
        }
        return remove;
    }
};

