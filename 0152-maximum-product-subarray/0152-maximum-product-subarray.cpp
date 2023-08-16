/*
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n=nums.size(),ans=nums[0];
        for(int i=1,imax=nums[0],imin=nums[0];i<n;++i){
            int temp=imax;
            imax=max({nums[i],imax*nums[i],imin*nums[i]});
            imin=min({nums[i],imin*nums[i],temp*nums[i]});
            ans=max(ans,imax);
        }
        return ans;
    }
};*/


class Solution {
public:
    int maxProduct(vector<int>& v) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        int n = v.size();
        int ans = v[0], p = 1;
        for(int i = 0;i<n;i++){
            p*=v[i];
            ans = max(ans, p);
            if (p==0){
                p = 1;
            }
        }
        p = 1;
        for(int i=n-1;i>=0;i--){
            p*=v[i];
            ans = max(ans, p);
            if (p==0){
                p = 1;
            }
        }
        return ans;
    }
};