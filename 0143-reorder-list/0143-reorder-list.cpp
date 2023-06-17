/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// O(N) time, O(1) space in total
class Solution{
public:
    void reorderList(ListNode *head) {

        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        if (!head || !head->next) return;
        
        // find the middle node: O(n)
        ListNode *p1 = head, *p2 = head->next;
        while (p2 && p2->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        
        // cut from the middle and reverse the second half: O(n)
        ListNode *head2 = p1->next;
        p1->next = NULL;
        
        p2 = head2->next;
        head2->next = NULL;
        while (p2) {
            p1 = p2->next;
            p2->next = head2;
            head2 = p2;
            p2 = p1;
        }
        
        // merge two lists: O(n)
        for (p1 = head, p2 = head2; p1; ) {
            auto t = p1->next;
            p1 = p1->next = p2;
            p2 = t;
        }
        
    }
};










/*
class Solution {
public:
    void reorderList(ListNode* head) {
        if ((!head) || (!head->next) || (!head->next->next)) return; // Edge cases
        
        stack<ListNode*> my_stack;
        ListNode* ptr = head;
        int size = 0;
        while (ptr != NULL) // Put all nodes in stack
        {
            my_stack.push(ptr);
            size++;
            ptr = ptr->next;
        }
        
        ListNode* pptr = head;
        for (int j=0; j<size/2; j++) // Between every two nodes insert the one in the top of the stack
        {
            ListNode *element = my_stack.top();
            my_stack.pop();
            element->next = pptr->next;
            pptr->next = element;
            pptr = pptr->next->next;
        }
        pptr->next = NULL;
    }
};*/