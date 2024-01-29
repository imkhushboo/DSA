/*

  Sort Linkedlist
  problem link : https://leetcode.com/problems/sort-list/
  video link : https://youtu.be/8ocB7a_c-Cc?si=WAS1qAUsbhgbY1XZ

*/

class Solution
{
public:
    ListNode *findmiddle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode *mergeList(ListNode *leftNode, ListNode *rightNode)
    {
        ListNode *newList = new ListNode(0);
        ListNode *ptr = newList;
        while (leftNode != NULL && rightNode != NULL)
        {
            if (leftNode->val < rightNode->val)
            {
                ptr->next = new ListNode(leftNode->val);
                ptr = ptr->next;
                leftNode = leftNode->next;
            }
            else
            {
                ptr->next = new ListNode(rightNode->val);
                ptr = ptr->next;
                rightNode = rightNode->next;
            }
        }

        while (leftNode != NULL)
        {
            ptr->next = new ListNode(leftNode->val);
            ptr = ptr->next;
            leftNode = leftNode->next;
        }

        while (rightNode != NULL)
        {
            ptr->next = new ListNode(rightNode->val);
            ptr = ptr->next;
            rightNode = rightNode->next;
        }

        return newList->next;
    }

    ListNode *sortList(ListNode *head)
    {
        // merge sort

        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *middle = findmiddle(head);
        ListNode *righthead = middle->next;
        ListNode *lefthead = head;
        middle->next = NULL;
        ListNode *leftNode = sortList(lefthead);
        ListNode *rightNode = sortList(righthead);

        return mergeList(leftNode, rightNode);
    }
};