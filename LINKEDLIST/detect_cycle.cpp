
/*
  DETECT A LOOP IN LINKEDLIST
  problem - link : https://leetcode.com/problems/linked-list-cycle/
  video - link : https://youtu.be/wiOo4DC5GGA?si=HRjZRSYaDm_dviw8

*/

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        // Naive approach

        map<ListNode *, int> mp;
        ListNode *ptr = head;

        while (ptr != NULL)
        {
            if (mp.find(ptr) != mp.end())
            {
                return true;
            }
            mp[ptr] = 1;
            ptr = ptr->next;
        }

        return false;

        // tc - O(N*LOG(N)) sc- O(N)

        // Hare and Tortoise algorithm

        ListNode *fast = head;
        ListNode *slow = head;

        while (fast != NULL and fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow)
            {
                return true;
            }
        }

        return false;
    }
};