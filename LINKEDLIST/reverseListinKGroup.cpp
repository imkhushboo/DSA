/*
   Reverse Nodes in K Groups
   problem link : https://leetcode.com/problems/reverse-nodes-in-k-group/
   video - link : https://youtu.be/lIar1skcQYI?si=5DiSYUeAUn9ew4ka
   Time complexity - O(N) + O(N)

*/

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;

        while (curr != NULL)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == NULL)
            return NULL;
        int temp = 1;
        ListNode *ptr = head;

        while (ptr != NULL and temp < k)
        {
            temp++;
            ptr = ptr->next;
        }
        if (ptr == NULL)
            return head;
        ListNode *prevNode = ptr->next;
        ptr->next = NULL;
        ListNode *newList = reverseList(head);
        head->next = reverseKGroup(prevNode, k);
        return newList;
    }
};