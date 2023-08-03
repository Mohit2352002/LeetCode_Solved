class Solution {
    void helper(vector<int>& nums, int tar, int idx, vector<int>& curr_ans, vector<vector<int>>& ans ){
        if(tar<0 || idx>nums.size()) return;
        if(tar==0){
            ans.push_back(curr_ans);
            return;
        }
        for(int i=idx;i<nums.size();++i){
            if(i>idx and nums[i]==nums[i-1]) continue;
            if(tar<nums[i]) break;
            curr_ans.push_back(nums[i]);
            helper(nums,tar-nums[i],i+1,curr_ans,ans);
            curr_ans.pop_back();
        }
        
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        vector<vector<int>> ans;
        vector<int>curr_ans;
        sort(candidates.begin(),candidates.end());
        helper(candidates,target,0,curr_ans,ans);
        return ans;
    }
};