class Solution {
    int helper(vector<int>&nums, int ind, int diff){
        if(ind==nums.size()) return 0;
        int ans=0;
        if(nums[ind]-nums[ind-1]==diff) ans=max(ans,1+helper(nums,ind+1,-diff));
        // for(int i=ind;i<nums.size();++i){
        //     if(nums[i]-nums[ind-1]==diff) ans=max(ans,1+helper(nums,i+1,-diff));
        // }
        return ans;
    }
public:
    int alternatingSubarray(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();++i)
            ans=max(1+helper(nums,i+1,1),ans);
        return ans<=1?-1:ans;
    }
};