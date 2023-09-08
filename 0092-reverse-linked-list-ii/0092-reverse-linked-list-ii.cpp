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
    ListNode* reverse(ListNode* head, int moves){
        ListNode* ans=new ListNode(-1);
        ListNode*temp=head;
        head=head->next;
        temp->next=ans;
        ans=temp;
        ListNode*change=temp;
        while(moves--){
            temp=head;
            head=head->next;
            temp->next=ans;
            ans=temp;
        }
        temp=head;
        head=head->next;
        temp->next=ans;
        ans=temp;
        change->next=head;
        return temp;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head or !head->next or left==right) return head;
        ListNode* start=new ListNode(-1,head);
        ListNode*ans=start;
        int count=right-left-1,skip=left-1;
        while(skip>0){
            start=start->next;
            --skip;
        }
        ListNode* temp=reverse(start->next,count);
        start->next=temp;
        return ans->next;
    }
};