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




/*
//worst approach
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        if(lists.empty()){
            return nullptr;
        }
        while(lists.size() > 1){
            lists.push_back(mergeTwoLists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == nullptr){
            return l2;
        }
        if(l2 == nullptr){
            return l1;
        }
        if(l1->val <= l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
*/





/*
//priority queue based approach
//either of the two class cmp or function<bool(ListNode* , ListNode*)>
// class comp {
//     public:
//     bool operator()(const ListNode* l, const ListNode* r) {
//         return l->val > r->val;
//     }
// };
class Solution{
    static bool comp(ListNode* a, ListNode* b){
        return a->val>b->val;
    }
    public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        if (lists.empty()) {
            return NULL;
        }
        priority_queue<ListNode*, vector<ListNode*>, function<bool(ListNode* , ListNode*)>> pq(comp);
        //if using class comp, then use below
        //priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        for(auto head:lists){
            if(head) pq.push(head);
        }
        if(pq.empty())  return NULL;
        ListNode*dummyHead=new ListNode(-1);
        ListNode*dummyTail=dummyHead;
        while(!pq.empty()){
            dummyTail->next=pq.top();
            pq.pop();
            dummyTail=dummyTail->next;
            if(dummyTail->next!=NULL) pq.push(dummyTail->next);
        }
        return dummyHead->next;
    }
};
*/









//Divide & Conquer
//best most optimised approach
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);

        if (lists.empty()) {
            return NULL;
        }

        return mergeKListsHelper(lists, 0, lists.size() - 1);
    }
    
private:
    ListNode* mergeKListsHelper(vector<ListNode*>& lists, int start, int end) {

        if(start>end) return NULL;

        if (start == end) {
            return lists[start];
        }

        if (start + 1 == end) {
            return merge(lists[start], lists[end]);
        }

        int mid = start + (end - start) / 2;

        ListNode* left = mergeKListsHelper(lists, start, mid);
        ListNode* right = mergeKListsHelper(lists, mid + 1, end);

        return merge(left, right);
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        
        while (l1 && l2) {

            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }

            curr = curr->next;
        }
        
        curr->next = l1 ? l1 : l2;
        
        return dummy->next;
    }
};