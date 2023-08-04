class Solution {
    bool valid(vector<int>&nums,int &speed, int rem_h,int &n){
        for(int i=0;i<n;++i){
            if(nums[i]<=speed) --rem_h;
            else rem_h-=ceil(1.0*nums[i]/speed);
            if(rem_h<0) return false;
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size(),low=1,high=0;
        for(int i=0;i<n;++i) high=max(high,piles[i]);
        if(n==h) return high;
        while(low<=high){
            int mid=low+((high-low)>>1);
            if(valid(piles,mid,h,n)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};