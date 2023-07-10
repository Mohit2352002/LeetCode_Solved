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
    int minDepth(TreeNode* root) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        if(!root) return 0;
        int ans=1;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                TreeNode*curr_node=q.front();
                q.pop();
                if(curr_node->left==NULL and curr_node->right==NULL) return ans;
                if(curr_node->left!=NULL) q.push(curr_node->left);
                if(curr_node->right!=NULL) q.push(curr_node->right);
            }
            ++ans;
        }
        return ans;
    }
};