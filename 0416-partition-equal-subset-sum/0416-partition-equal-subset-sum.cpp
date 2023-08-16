static auto _ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();


class Solution {
    int n;
    vector<vector<int>>dp;
    bool helper(vector<int>&nums, int idx, int sum){
        if(sum==0) return true;
        else if(sum<0 or idx>=n) return false;
        else if(dp[idx][sum]!=-1) return dp[idx][sum];
        return dp[idx][sum]=(helper(nums,idx+1,sum) or helper(nums, idx+1,sum-nums[idx]));
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        n=nums.size();
        for(int el:nums) sum+=el;
        dp.resize(n,vector<int>((sum/2)+1,-1));
        if(sum&1) return false;
        return helper(nums,0,sum/2);
    }
};