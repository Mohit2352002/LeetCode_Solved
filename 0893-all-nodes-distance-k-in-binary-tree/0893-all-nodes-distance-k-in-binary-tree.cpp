/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
public:
    void mark_parent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> & parent){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            if(current->left){
                parent[current->left] = current;
                q.push(current->left);
            }
            if(current->right){
                parent[current->right] = current;
                q.push(current->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        unordered_map<TreeNode*, TreeNode*> parent;
        mark_parent(root, parent);
        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target]=true;
        int dis = 0;
        while(!q.empty()){
            int n = q.size();
            if(dis==k) break;
            dis++;
            for(int i=0; i<n; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left] = true;
                }
                if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right] = true;
                }
                if(parent[curr] && !vis[parent[curr]]){
                    q.push(parent[curr]);
                    vis[parent[curr]] = true;
                }

            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};
/*
class Solution {
    unordered_map<TreeNode*,TreeNode*>parent;
    void findParent(TreeNode* node, TreeNode*par){
        parent[node]=par;
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
                if(curr_node->left and !vis[curr_node->left]){
                    q.push(curr_node->left);
                    vis[curr_node->left]=true;;
                }
                if(curr_node->right and !vis[curr_node->right]){
                    q.push(curr_node->right);
                    vis[curr_node->right]=true;
                }
                if(parent[curr_node] and !vis[parent[curr_node]]){ 
                    q.push(parent[curr_node]);
                    vis[parent[curr_node]]=true;
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
};*/