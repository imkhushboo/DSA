
/*
  ADD TWO NUMBERS
  problem - link : https://leetcode.com/problems/add-two-numbers/

*/
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ans = new ListNode(0);
        ListNode *ptr = ans;
        int carry = 0;
        while (l1 != NULL or l2 != NULL)
        {
            int val1 = 0;
            int val2 = 0;
            if (l1 != NULL)
            {
                val1 = l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL)
            {
                val2 = l2->val;
                l2 = l2->next;
            }
            ptr->next = new ListNode((val1 + val2 + carry) % 10);
            carry = (val1 + val2 + carry) / 10;
            ptr = ptr->next;
        }
        while (carry > 0)
        {
            ptr->next = new ListNode(carry % 10);
            carry = (carry) / 10;
            ptr = ptr->next;
        }
        return ans->next;
    }
};