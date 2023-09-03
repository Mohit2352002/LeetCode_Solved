/*
class Solution {
public:
    int jump(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int ans = 0, left = 0, right = 0;
        while(right < nums.size() - 1){
            int maxi = 0;
            for (int i = left; i <= right; ++i) 
                maxi = max(maxi, i + nums[i]);
            left = right + 1;
            right = maxi;
            ++ans;
        }
        return ans;
    }
};*/

class Solution {
public:
    int jump(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int ans=1,curr_max=nums[0],net_max=nums[0],n=nums.size();
        if(n==1) return 0;
        for(int i=1;i<n;++i){
            if(i>curr_max){
                ++ans;
                curr_max=net_max;
            }
            net_max=max(i+nums[i],net_max);
        }
        return ans;
    }
};





/*
//greedy
class Solution {
public:
    int jump(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        if(nums.size()<3) return nums.size()-1;
        int curr=0, maxj=0,ans=0;
        for(int i=0;i<nums.size()-1;++i){
            maxj=max(maxj,i+nums[i]);
            if(maxj>=nums.size()-1){
                ++ans;
                break;
            }
            if(i==curr){
                ++ans;
                curr=maxj;
            }
        }
        return ans;
    }
};












/*
//tabulation
class Solution {
public:
    int jump(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int n = size(nums);
        vector<int> dp(n, 10001);
        dp[n-1]=0; //start from last index. No jumps required to reach end if we are already here
        //same as above. For each index, explore all jump sizes and use the one requiring minimum jumps to reach end
        for(int i = n - 2; i >= 0; i--) 
            for(int jumpLen = 1; jumpLen <= nums[i]; jumpLen++) 
                dp[i]=min(dp[i],1+dp[min(n-1,i+jumpLen)]);  //min(n-1,i+jumpLen) for bounds handling
        return dp[0];
    }
};*/











/*
//recursive + memo
class Solution {
    int helper(int i,vector<int>&nums,vector<int>&dp){
        if(i>=nums.size()-1) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=1e4;
        for(int j=i+1;j<=i+nums[i];++j){
            ans=min(ans,1+helper(j,nums,dp));
        }
        return dp[i]=ans;
    }
public:
    int jump(vector<int>& nums) {
        if(nums.size()<3) return nums.size()-1;
        vector<int>dp(nums.size()+1,-1);
        return helper(0,nums,dp);
    }
};*/