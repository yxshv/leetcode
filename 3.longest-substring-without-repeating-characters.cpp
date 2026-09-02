#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        char *pointer = &s[0];
        char *start = &s[0];
        char *substr_start_ptr = pointer;

        int ans = 0;
        int length = 0;
        int total_length = s.length();

        char *included_characters[128] = {};
        while ((pointer - start) < total_length)
        {
            if (included_characters[(unsigned char)(pointer[0])] == nullptr || substr_start_ptr - included_characters[(unsigned char)((pointer[0]))] > 0)
            {
                if (substr_start_ptr - included_characters[(unsigned char)((pointer[0]))] < 0) {
                    included_characters[(unsigned char)((pointer[0]))] = nullptr;
                }
                length++;
            }
            else
            {
                ans = max(length, ans);
                length = pointer - included_characters[(unsigned char)(pointer[0])];
                substr_start_ptr = included_characters[(unsigned char)(pointer[0])];
                substr_start_ptr++;
            }
            included_characters[(unsigned char)(pointer[0])] = pointer;
            pointer++;
        }

        ans = max(length, ans);

        return ans;
    }
};
// @lc code=end