#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size(),
            w = 0,
            l = 0, r = n - 1,
            maxL = 0, maxR = 0;
        while (l <= r)
        {
            if (maxL < maxR)
            {
                w += max(0, maxL - height[l]);
                maxL = max(maxL, height[l]);
                l++;
            }
            else
            {
                w += max(0, maxR - height[r]);
                maxR = max(maxR, height[r]);
                r--;
            }
        }
        return w;
    }
};
// @lc code=end
