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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);

        if(!head || !head->next || k==1) return head;

        ListNode *dummy= new ListNode(-1);
        dummy->next=head;
        ListNode *curr=head;
        int count=0;
         
        while(curr!=NULL){
            ++count;
            curr=curr->next;
        }

        ListNode* slow=dummy, *fast=dummy;
        while(count>=k){
            curr=slow->next;
            fast=curr->next;
            for(int i=1;i<k;++i){
                curr->next=fast->next;
                fast->next=slow->next;
                slow->next=fast;
                fast=curr->next;
            }
            slow=curr;
            count-=k;
        }

        return dummy->next;
    }
};