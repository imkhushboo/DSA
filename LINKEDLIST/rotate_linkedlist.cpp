/*
 Rotate List
  problem - link : https://leetcode.com/problems/rotate-list/
  video - link : https://youtu.be/uT7YI7XbTY8?si=z42Gh8NIIX_BDOuR
*/

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {

        if (head == NULL)
            return head;
        ListNode *ptr = head;

        int len = 1;

        while (ptr->next != NULL) // O(N)
        {
            len++;
            ptr = ptr->next;
        }

        int rotation = k % len;

        if (rotation == 0)
            return head;

        // link end node to start node
        ptr->next = head;
        ptr = head;
        int temp = len - rotation;

        while (--temp) // ~ O(N)
        {
            ptr = ptr->next;
        }

        head = ptr->next;
        ptr->next = NULL;

        return head;
    }
};