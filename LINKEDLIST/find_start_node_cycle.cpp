/*
 find the node where the cycle begins. If there is no cycle, return null.
  problem - link : https://leetcode.com/problems/linked-list-cycle-ii/
  video - link : https://youtu.be/2Kd0KKmmHFc?si=5h0XmcIqMxoI61RC
*/

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        // naive approach

        map<ListNode *, int> mp;
        ListNode *ptr = head;
        while (ptr != NULL)
        {
            if (mp.find(ptr) != mp.end())
                return ptr;
            mp[ptr] = 1;
            ptr = ptr->next;
        }

        return NULL;

        // hare and tortoise algorithm (optimal approach)
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != NULL and fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow)
            {
                break;
            }
        }

        if (fast == NULL or fast->next == NULL)
            return NULL;

        fast = head;

        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
};