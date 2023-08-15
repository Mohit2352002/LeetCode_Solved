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
static auto _ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

/*
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head or !head->next) return head;
        ListNode*end=head,*ans=head;
        ListNode* temp=new ListNode(-1,head);
        int count=1;
        while(end->next!=NULL){
            end=end->next;
            ++count;
        }
        while(ans!=NULL and ans->val>=x){
            ans=ans->next;
        }
        if(ans==NULL) return head;
        while(count--){
            if(temp->next->val>=x){
                end->next=temp->next;
                end=end->next;
                temp->next=temp->next->next;
            }
            else temp=temp->next;
        }
        end->next=NULL;
        return ans;
    }
};*/





class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *greater = new ListNode(0),*smaller = new ListNode(0);
        ListNode *greaterTail = greater,*smallerTail = smaller;
        while(head != NULL){
            if(head->val < x){
                smallerTail->next = head;
                smallerTail = smallerTail->next;
            }
            else{
                greaterTail->next = head;
                greaterTail = greaterTail->next;
            }
            head = head->next;
        }
        smallerTail->next = greater->next;
        greaterTail->next = NULL;
        return smaller->next;
    }
};