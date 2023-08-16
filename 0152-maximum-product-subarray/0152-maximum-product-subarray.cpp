static auto _ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();


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
    int maxProduct(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n=nums.size(),ans=nums[0],prefix=1,suffix=1;
        for(int i=0;i<n;++i){
            if(suffix==0) suffix=1;
            if(prefix==0) prefix=1;
            prefix*=nums[i];
            suffix*=nums[n-i-1];
            ans=max({ans,suffix,prefix});
        }
        return ans;
    }
};