#include "/home/volcano/.leetcode/header.cpp"
/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int pivot = nums[0], low = 0, high = nums.size() - 1, mid;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (mid > 0 and nums[mid] < nums[mid - 1])
                return nums[mid];
            if (nums[mid] >= pivot)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return nums[0];
    }
};
// @lc code=end
