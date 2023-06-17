/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        if(head==NULL || !head->next or !head->next->next) return false;
        ListNode *slow=head->next;
        ListNode *fast=head->next->next;
        while(slow!=fast){
            if(fast==NULL||fast->next==NULL){
                return false;
            }
            slow=slow->next;
            fast=fast->next->next;
        }
        return true;
    }
};