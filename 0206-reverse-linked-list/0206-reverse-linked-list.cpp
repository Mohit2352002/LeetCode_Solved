class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

         if(!head or !head->next)
            return head;
        
        ListNode* prev = NULL ;
        ListNode* forw = NULL ;
        
        while(head){
            forw = head->next ;
            head->next = prev ;
            prev = head ;
            head = forw ;
        }
    
        return prev;
    }
};