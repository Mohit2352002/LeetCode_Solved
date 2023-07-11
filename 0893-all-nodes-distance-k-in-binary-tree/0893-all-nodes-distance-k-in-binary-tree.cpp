/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    unordered_map<int,TreeNode*>parent;
    void findParent(TreeNode* node, TreeNode*par){
        parent[node->val]=par;
        if(node->left!=NULL) findParent(node->left,node);
        if(node->right!=NULL) findParent(node->right,node);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        if(!root) return {};
        findParent(root,NULL);
        queue<TreeNode*>q;
        q.push(target);
        unordered_map<TreeNode*,bool>vis;
        int dist=0;
        vector<int>ans;
        vis[target]=true;
        while(!q.empty() and dist!=k){
            int sz=q.size();
            while(sz--){
                TreeNode* curr_node=q.front();
                q.pop();
                if(curr_node->left!=NULL and !vis[curr_node->left]){
                    q.push(curr_node->left);
                    vis[curr_node->left]=true;;
                }
                if(curr_node->right!=NULL and !vis[curr_node->right]){
                    q.push(curr_node->right);
                    vis[curr_node->right]=true;
                }
                if(parent[curr_node->val]!=NULL and !vis[parent[curr_node->val]]){ 
                    q.push(parent[curr_node->val]);
                    vis[parent[curr_node->val]]=true;
                }
            }
            ++dist;
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};