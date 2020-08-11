class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.resize(m);
        nums1.reserve(m + n);
        auto i = nums1.begin();
        auto j = nums2.begin();
        while (i != nums1.end() && j != nums2.end()) {
            if (*i <= *j) {
                ++i;
            }
            else {
                nums1.insert(i, *j);
                ++j;
            }
        }
        while (j != nums2.end()) {
            nums1.push_back(*j);
            ++j;
        }
    }
};

