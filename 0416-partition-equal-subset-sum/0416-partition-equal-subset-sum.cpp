static auto _ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();



/*
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
};*/



class Solution{
public:
    bool canPartition(vector<int>&nums){
        int sum=0,n=nums.size();
        for(int &el:nums) sum+=el;
        if(sum&1) return false;
        int halfsum=sum/2;
        vector<bool>dp(halfsum+1,false);
        dp[0]=true;
        for(int i=0;i<n;++i){
            for(int val=halfsum;val>=nums[i];--val){
                if(dp[val-nums[i]]) dp[val]=true;
            }
        }
        return dp[halfsum];
    }
};
