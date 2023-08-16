class Solution {
public:
    int maxProduct(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n=nums.size(),ans=nums[0],imax=nums[0],imin=nums[0];
        for(int i=1;i<n;++i){
           if(nums[i]<0) swap(imin,imax);
           imax=max(nums[i],imax*nums[i]);
           imin=min(nums[i],imin*nums[i]);
           ans=max(ans,imax);
        }
        return ans;
    }
};