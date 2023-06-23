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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        if(!head) return NULL;
        else if(!head->next) return new TreeNode(head->val);
        ListNode* slow=head, *fast=head, *slow_prev=NULL;
        while(fast!=NULL and fast->next!=NULL){
            fast=fast->next->next;
            slow_prev=slow;
            slow=slow->next;
        }
        TreeNode*root=new TreeNode(slow->val);
        root->right=sortedListToBST(slow->next);
        slow_prev->next=NULL;
        root->left=sortedListToBST(head);
        return root;
    }
};