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
    int prev=-1,ans=INT_MAX;
public:
//inorder traversal gives sorted output in BST, left->root->right
    int minDiffInBST(TreeNode* root) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        if(root->left) minDiffInBST(root->left);
        if(prev!=-1) ans=min(root->val-prev,ans);
        prev=root->val;
        if(root->right) minDiffInBST(root->right);
        return ans;
    }
};