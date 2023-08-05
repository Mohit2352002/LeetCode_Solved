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
 static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
    vector<TreeNode*>helper(int start,int end,map<pair<int,int>,vector<TreeNode*>>&memo){
        if(end<start) return {NULL};
        else if(end==start) return {new TreeNode(end)};
        if(memo.find({start,end})!=memo.end()) return memo[{start, end}];
        vector<TreeNode*>ans;
        for(int i=start;i<=end;++i){
            vector<TreeNode*>leftTrees=helper(start,i-1,memo);
            vector<TreeNode*>rightTrees=helper(i+1,end,memo);
            for(TreeNode* &leftTree:leftTrees){
                for(TreeNode* &rightTree:rightTrees){
                    TreeNode* root=new TreeNode(i,leftTree,rightTree);
                    ans.push_back(root);
                }
            }
        }
        return memo[{start, end}]=ans;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        map<pair<int,int>,vector<TreeNode*>>memo;
        return helper(1,n,memo);
    }
};