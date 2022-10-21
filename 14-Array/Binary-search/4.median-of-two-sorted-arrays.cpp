#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();
        if (m > n)
            return findMedianSortedArrays(nums2, nums1);
        int total = m + n, half = (total + 1) / 2, low = 0, high = m;
        while (low <= high)
        {
            int p1 = (low + high) / 2;
            int p2 = half - p1;

            int l1 = p1 > 0 ? nums1[p1 - 1] : INT_MIN;
            int r1 = p1 < m ? nums1[p1] : INT_MAX;

            int l2 = p2 > 0 ? nums2[p2 - 1] : INT_MIN;
            int r2 = p2 < n ? nums2[p2] : INT_MAX;

            if (l1 <= r2 and l2 <= r1)
            {
                if (total % 2 == 0)
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                return max(l1, l2);
            }
            else if (l1 > r2)
                high = p1 - 1;
            else
                low = p1 + 1;
        }
        return 0.0;
    }
};
// @lc code=end
