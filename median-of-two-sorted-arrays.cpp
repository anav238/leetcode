class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if(m > n)
            return findMedianSortedArrays(nums2, nums1);
        int N = m + n, left = 0, right = m;
        while (left <= right) {
            int i = (left + right) / 2;
            int j = (m + n + 1) / 2 - i;
            if ((j == 0 || i == m || nums2[j - 1] <= nums1[i])
                && (i == 0 || j == n || nums1[i - 1] <= nums2[j])) {
                int l_med;
                if (i == 0)
                    l_med = nums2[j - 1];
                else if (j == 0)
                    l_med = nums1[i - 1];
                else l_med = max(nums1[i - 1], nums2[j - 1]);

                if (N % 2 == 0) {
                    int r_med;
                    if (i == m)
                        r_med = nums2[j];
                    else if (j == n)
                        r_med = nums1[i];
                    else r_med = min(nums1[i], nums2[j]);
                    return (l_med + r_med) / 2.0;
                }
                return l_med;
            }
            else if (j > 0 && i < m && nums2[j - 1] >= nums1[i])
                left = i + 1;
            else if (i > 0 && j < n && nums1[i - 1] > nums2[j])
                right = i - 1;
        }
        return -1;
    }
};
