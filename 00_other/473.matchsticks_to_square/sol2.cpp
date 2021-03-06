#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

class Solution
{
public:
    bool makesquare(vector<int> &nums)
    {
        if (nums.empty() || nums.size() < 4)
            return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 4 != 0)
            return false;
        vector<int> sums(4, 0);
        sort(nums.rbegin(), nums.rend());
        return helper(nums, sums, 0, sum / 4);
    }
    bool helper(vector<int> &nums, vector<int> &sums, int pos, int target)
    {
        if (pos >= nums.size())
        {
            return sums[0] == target && sums[1] == target && sums[2] == target;
        }
        for (int i = 0; i < 4; ++i)
        {
            if (sums[i] + nums[pos] > target)
                continue;
            sums[i] += nums[pos];
            if (helper(nums, sums, pos + 1, target))
                return true;
            sums[i] -= nums[pos];
        }
        return false;
    }
};