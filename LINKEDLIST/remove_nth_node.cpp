/*
  Remove Nth Node From End of List
  problem - link : https://leetcode.com/problems/remove-nth-node-from-end-of-list/

*/

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int total_node = 0;
        ListNode *ptr = head;
        while (ptr != NULL)
        {
            ptr = ptr->next;
            total_node++;
        }

        ptr = head;
        int temp = total_node - n;
        while (ptr != NULL)
        {
            // cout<<"--\n";
            if (temp == 0 and ptr == head)
            {
                return ptr->next;
            }
            else if (temp - 1 == 0)
            {
                // cout<<"--\n";
                ptr->next = ptr->next->next;
                break;
            }
            ptr = ptr->next;
            temp--;
        }

        return head;
    }
};