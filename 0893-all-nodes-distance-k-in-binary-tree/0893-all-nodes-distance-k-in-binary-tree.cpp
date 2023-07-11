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
        set<TreeNode*>vis;
        int dist=0;
        vector<int>ans;
        vis.insert(target);
        while(!q.empty() and dist!=k){
            int sz=q.size();
            while(sz--){
                TreeNode* curr_node=q.front();
                q.pop();
                if(curr_node->left!=NULL and vis.find(curr_node->left)==vis.end()){
                    q.push(curr_node->left);
                    vis.insert(curr_node->left);
                }
                if(curr_node->right!=NULL and vis.find(curr_node->right)==vis.end()){
                    q.push(curr_node->right);
                    vis.insert(curr_node->right);
                }
                if(parent[curr_node->val]!=NULL and vis.find(parent[curr_node->val])==vis.end()){ 
                    q.push(parent[curr_node->val]);
                    vis.insert(parent[curr_node->val]);
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