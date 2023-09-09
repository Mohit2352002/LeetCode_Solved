static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();


class Solution {
    vector<int>dp;
    int helper(vector<int>&nums, int target){
        int n=nums.size();
        if(target==0) return 1;
        if(dp[target]!=-1) return dp[target];
        int ways=0;
        for(int i=0;i<n;++i){
            if(nums[i]<=target) ways+=helper(nums,target-nums[i]);
        }
        return dp[target]=ways;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(target+1,-1);
        return helper(nums,target);
    }
};