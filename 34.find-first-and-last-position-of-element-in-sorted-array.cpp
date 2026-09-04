#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution
{
public:
    int total_length = 0;

    int last_pos = -1;
    int first_pos = -1;

    void find_target(vector<int> &nums, int &target, int start_index, int end_index)
    {
        int n = end_index - start_index + 1;

        if (n <= 0) {
            return;
        }

        int checking_index = 0;

        if (n % 2 == 0)
        {
            checking_index = start_index + (n) / 2;
        }
        else
        {
            checking_index = start_index + (n - 1) / 2;
        }

        int middle_val = nums[checking_index];
        if (middle_val == target)
        {
            if (last_pos == -1)
            {
                if (checking_index == total_length-1)
                {
                    last_pos = checking_index;
                }
                else if (nums[checking_index + 1] != target)
                {
                    last_pos = checking_index;
                }
                else
                {
                    find_target(nums, target, checking_index + 1, end_index);
                }
            }

            if (first_pos == -1)
            {
                if (checking_index == 0)
                {
                    first_pos = checking_index;
                }
                else if (nums[checking_index - 1] != target)
                {
                    first_pos = checking_index;
                }
                else
                {
                    find_target(nums, target, start_index, checking_index - 1);
                }
            }
        }
        else if (middle_val < target)
        {
            find_target(nums, target, checking_index + 1, end_index);
        }
        else
        {
            find_target(nums, target, start_index, checking_index - 1);
        }
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        total_length = nums.size();

        find_target(nums, target, 0, total_length-1);

        return {first_pos, last_pos};
    }
};
// @lc code=end
