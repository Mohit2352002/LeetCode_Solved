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
    int maxLevelSum(TreeNode* root) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        queue<TreeNode*>q;
        int curr_level=0,curr_sum,sum=INT_MIN,level=1,n;
        q.push(root);
        while(!q.empty()){
            n=q.size();
            curr_level++;
            curr_sum=0;
            while(n--){
                TreeNode*temp=q.front();
                q.pop();
                curr_sum+=temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(curr_sum>sum){ 
                level=curr_level;
                sum=curr_sum;
            }   
        }
        return level;
    }
};