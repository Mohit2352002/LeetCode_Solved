class Solution {
public:
    int maxProduct(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n=nums.size(),ans=nums[0],imax=nums[0],imin=nums[0];
        for(int i=1;i<n;++i){
            int temp=imax;
            imax=max({nums[i],imax*nums[i],imin*nums[i]});
            imin=min({nums[i],imin*nums[i],temp*nums[i]});
            ans=max(ans,imax);
        }
        return ans;
    }
};