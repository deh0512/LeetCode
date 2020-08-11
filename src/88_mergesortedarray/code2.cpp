class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.resize(m + n);
        auto i = nums1.rbegin();
        auto j = nums1.rbegin() + n;
        auto k = nums2.rbegin();
        while (j != nums1.rend() && k != nums2.rend()) {
            if (*j > *k) {
                *i = *j;
                ++j;
            }
            else {
                *i = *k;
                ++k;
            }
            ++i;
        }
        while (k != nums2.rend()) {
            *i = *k;
            ++k;
            ++i;
        }
    }
};

