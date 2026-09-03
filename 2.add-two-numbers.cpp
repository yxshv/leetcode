#include <2.add-two-numbers.h>

/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int num = l1->val + l2->val;

        ListNode* first_node = nullptr;
        ListNode* last_node = nullptr;

        while (l1 != nullptr || l2 != nullptr || num > 0)
        {
            int current_item = num % 10;
            ListNode* new_node = new ListNode(current_item);

            if (last_node != nullptr) {
                last_node->next = new_node;
            }

            last_node = new_node;

            if (first_node == nullptr) {
                first_node = new_node;
            }

            num = (num - current_item) / 10;

            if (l1 != nullptr && l1->next != nullptr)
            {
                l1 = l1->next;
                num += l1->val;
            }
            else
            {
                l1 = nullptr;
            }

            if (l2 != nullptr && l2->next != nullptr)
            {
                l2 = l2->next;
                num += l2->val;
            }
            else
            {
                l2 = nullptr;
            }
        }

        return first_node;
    }
};
// @lc code=end
