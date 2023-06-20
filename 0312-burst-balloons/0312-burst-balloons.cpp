/*
// Recursion + Memoization (top down approach)
class Solution {
    int dp[301][301];
    int helper(int start,int end,vector<int>& nums){
        if(start>end) return 0;
        if(dp[start][end]!=-1) return dp[start][end];
        if(start==end) return dp[start][end]=nums[start]*nums[start+1]*nums[start-1];
        int maxi=INT_MIN;
        for(int burst=start;burst<=end;++burst){
            maxi=max(maxi, nums[burst]*nums[start-1]*nums[end+1] +
            helper(start,burst-1,nums)+ helper(burst+1,end,nums));
        }
        return dp[start][end]=maxi;
    }
public:
    int maxCoins(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return nums[0]*nums[1]+max(nums[0],nums[1]);
        memset(dp,-1,sizeof(dp));
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        return helper(1,n,nums);
    }
};*/

















//Tabulation (Bottom Up Approach)
class Solution {
public:
    int dp[302][302];
    int maxCoins(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return nums[0]*nums[1]+max(nums[0],nums[1]);
        memset(dp,0,sizeof(dp));
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        for(int start=n;start>=1;--start){
            for(int end=start;end<=n;++end){
                int maxi=INT_MIN;
                for(int burst=start;burst<=end;++burst){
                    maxi=max(maxi, nums[burst]*nums[start-1]*nums[end+1] +
                   dp[start][burst-1]+ dp[burst+1][end]);
                }
                dp[start][end]=maxi; 
            }
        }
        return dp[1][n];
    }
};