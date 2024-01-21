/*
  Design Browser History
 problem - link : https://leetcode.com/problems/design-browser-history/
 video - link : https://youtu.be/mG3KLugbOdc?si=B8lbblxSeUGMsNz5

*/

class Node
{
public:
    string data;
    Node *back;
    Node *next;
    Node(string s) : data(s), next(nullptr), back(nullptr) {}
};
class BrowserHistory
{
public:
    Node *currnode = NULL;
    Node *head = NULL;
    BrowserHistory(string homepage)
    { // O(1)
        currnode = new Node(homepage);
    }

    void visit(string url)
    { // O(1)
        Node *nptr = new Node(url);
        currnode->next = nptr;
        nptr->back = currnode;
        currnode = nptr;
    }

    string back(int steps)
    { // O(steps)
        while (steps--)
        {

            if (currnode->back == NULL)
            {
                break;
            }
            else
            {
                currnode = currnode->back;
            }
        }
        return currnode->data;
    }

    string forward(int steps)
    { // O(steps)
        while (steps--)
        {

            if (currnode->next == NULL)
            {
                break;
            }
            else
            {
                currnode = currnode->next;
            }
        }

        return currnode->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */