
/*
Delete the Middle Node of a Linked List
 problem - link : https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
 video - link : https://youtu.be/ePpV-_pfOeI?si=1JbqLWVKC9VvrVxj
*/

class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        // naive approach
        int cnt_nodes = 0;

        ListNode *ptr = head;

        while (ptr != NULL)
        {
            cnt_nodes++;
            ptr = ptr->next;
        }

        int mid = cnt_nodes / 2;

        if (mid == 0)
            return NULL;

        ptr = head;

        while (mid > 0)
        {

            mid = mid - 1;

            if (mid == 0)
            {
                ptr->next = ptr->next->next;
            }
            else
            {
                ptr = ptr->next;
            }
        }

        return head;

        // optimal approcah hare and tortoise algo

        if (head == NULL || head->next == NULL)
            return NULL;

        ListNode *fast = head->next->next;
        ListNode *slow = head;

        while (fast != NULL and fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return head;
    }
};