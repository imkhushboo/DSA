/*
 Delete Node in a Linked List
 problem - link : https://leetcode.com/problems/delete-node-in-a-linked-list/

*/

// O(N)
class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        ListNode *curr = node;

        while (curr->next->next != NULL)
        {
            curr->val = curr->next->val;
            curr = curr->next;
        }
        curr->val = curr->next->val;
        curr->next = NULL;
    }
};

// O(1)

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};