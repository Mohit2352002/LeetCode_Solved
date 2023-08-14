static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
    vector<int>dp;
    int n;
    int helper(vector<int>&nums, int idx){
        if(idx>=n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        return dp[idx]=nums[idx]+min(helper(nums,idx+1),helper(nums,idx+2));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        n=cost.size();
        dp.resize(n+1,-1);
        return min(helper(cost,0),helper(cost,1));
    }
};