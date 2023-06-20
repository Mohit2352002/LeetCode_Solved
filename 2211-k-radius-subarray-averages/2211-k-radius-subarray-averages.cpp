class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int n=nums.size();
        if(k==0) return nums;
        vector<int>ans(n,-1);
        if(2*k>=n) return ans;
        long long sum=0,div=2*k+1;
        for(int i=0;i<2*k;++i) sum+=nums[i];
        for(int i=k;i<n-k;++i){
            if(i-k-1>=0) sum-=nums[i-k-1];
            if(i+k<n) sum+=nums[i+k];
            ans[i]=sum/div;
        }
        return ans;
    }
};