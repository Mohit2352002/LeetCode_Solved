class Solution {
    vector<vector<int>>dp;
    int n;
    // int helper(int i,int p,vector<int>& nums){
    //     if(p==0) return 0;
    //     if(i>=n) return 0;
    //     if(dp[i][p]!=-1) return dp[i][p];
    //     dp[i][p]=min(helper(i+1,p,nums),max(abs(nums[i]-nums[i+1]), helper(i+2, p-1,nums)));

    // }
    int pairs(vector<int>&nums, int peak){
        int count=0,i=0;
        while(i<n-1){
            if(nums[i+1]-nums[i]<=peak){
                ++i;
                ++count;
            }
            ++i;
        }
        return count;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        if(p==0) return 0;
        sort(nums.begin(),nums.end());
        n=nums.size();
        int low=0, high=nums[n-1]-nums[0];
        while(low<high){
            int mid=low+((high-low)/2);
            if(pairs(nums,mid)>=p){
                high=mid;
            }else low=mid+1;
        }
        return low;
    }
};
