class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        return (
            findKth(nums1, nums2, (m + n + 1) / 2) 
            + findKth(nums1, nums2, (m + n + 2) / 2)) / 2.0;
    }

    int findKth(const vector<int>& nums1, const vector<int>& nums2, int k) {
        if (nums1.empty()) return nums2[k - 1];
        if (nums2.empty()) return nums1[k - 1];
        // the first one
        if (k == 1) {
            return min(nums1[0], nums2[0]);
        }

        // throw away k/2 elements
        int i = min((int)nums1.size(), k / 2);
        int j = min((int)nums2.size(), k / 2);
        if (nums1[i - 1] > nums2[j - 1]) {
            return findKth(nums1, vector<int>(nums2.begin() + j, nums2.end()), k - j);
        }
        else
        {
            return findKth(vector<int>(nums1.begin() + i, nums1.end()), nums2, k - i);
        }
        return 0;
    }
};