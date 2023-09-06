static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();


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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>ans(k,NULL);
        int i=0,n=0;
        ListNode*temp=head;
        while(temp){
            ++n;
            temp=temp->next;
        }
        // if(k>=n){
        //     while(i!=n){
        //         ListNode*temp=head;
        //         head=head->next;
        //         temp->next=NULL;
        //         ans[i++]=temp;
        //     }
        // }
        // else{
            int rem=n%k,nec=n/k;
            while(head){
                int el=0;
                ListNode*temp=new ListNode(-1,head);
                ans[i++]=head;
                while(el!=nec){
                    temp=temp->next;
                    head=head->next;
                    ++el;
                }
                if(rem){
                    --rem;
                    head=head->next;
                    temp=temp->next;
                }
                temp->next=NULL;
            }
        // }
        return ans;
    }
};