class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int>ans;
        vector<int>freq(51,0);
        for(int i=0;i<k;++i){
            if(nums[i]<0) ++freq[-nums[i]];
        }
        int count=0,n=nums.size();
        for(int i=50;i>0;--i){
            count+=freq[i];
            if(count>=x){
                ans.push_back(-i);
                break;
            }
        }
        if(count<x) ans.push_back(0);
        for(int i=k;i<n;++i){
            if(nums[i-k]<0) --freq[-nums[i-k]];
            if(nums[i]<0) ++freq[-nums[i]];
            count=0;
            for(int i=50;i>0;--i){
                count+=freq[i];
                if(count>=x){
                    ans.push_back(-i);
                    break;
                }
            }
            if(count<x) ans.push_back(0);
        }
        return ans;
    }
};