#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int
            h = numbers.size() - 1,
            l = 0;
        while (l < h)
        {
            int curr_sum = numbers[l] + numbers[h];
            if (curr_sum == target)
                return {l + 1, h + 1};
            else if (curr_sum < target)
                l++;
            else
                h--;
        }
        return {-1, -1};
    }
};
// @lc code=end
