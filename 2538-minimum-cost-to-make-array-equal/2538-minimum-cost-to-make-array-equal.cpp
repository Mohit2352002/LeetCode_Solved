class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int n=nums.size();
        if(n==1) return 0;
        vector<pair<int,int>>vec(n);
        long long n_el=0;
        for(int i=0;i<n;++i){
            vec[i]={nums[i],cost[i]};
            n_el+=cost[i];
        }
        sort(vec.begin(),vec.end());
        int i=0,median;
        long long idx=0,ans=0,median_idx=(n_el+1)/2;
        while(idx<median_idx){
            idx+=vec[i].second;
            median=vec[i++].first;
        }
        for(i=0;i<n;++i){
            ans+=(1ll*abs(nums[i]-median)*cost[i]);
        }
        return ans;
    }
};












/*
long long minCost(vector<int>& nums, vector<int>& cost) {
       long long N = (sum+1)/2;
       int x = -1;
       for(int i=0;i<n;i++){
           N -= arr[i].second;
           if(N<=0){
            x = arr[i].first;
            break;
           }
       }
     long long ans = 0;
     for(int i=0;i<n;i++){
      ans += (long long)abs( (long long) x*cost[i]-(long long) nums[i]*cost[i]);   
     }
     return ans;
    }
    */