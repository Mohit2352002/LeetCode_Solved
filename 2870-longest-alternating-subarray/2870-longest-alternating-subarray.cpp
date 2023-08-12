static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

/*
class Solution {
    int helper(vector<int>&nums, int ind, int diff){
        if(ind==nums.size()) return 0;
        int ans=0;
        if(nums[ind]-nums[ind-1]==diff) ans=max(ans,1+helper(nums,ind+1,-diff));
        return ans;
    }
public:
    int alternatingSubarray(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();++i)
            ans=max(1+helper(nums,i+1,1),ans);
        return ans<=1?-1:ans;
    }
};*/


class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n=nums.size(),diff=1,i=0,j=1,ans=-1;
        while(j<n){
            if(nums[j]-nums[j-1]==diff){
                ans=max(ans,j-i+1);
                diff*=-1;
            }else if(diff==-1 and nums[j]-nums[j-1]==-diff){
                i=j-1;
                ans=max(ans,j-i+1);
            }else{
                diff=1;
                i=j;
            }
            ++j;
        }
        return ans>1?ans:-1;
    }
};