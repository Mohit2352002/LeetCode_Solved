static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
    bool valid(long long ans, vector<int>&nums, int &n, int &sz){
        long long sum=min<long long>(ans,nums[0]);
        if(sum>=(1ll*ans*n)) return true;
        for(int i=1;i<sz;++i){
            sum+=min<long long>(ans,nums[i]);
            if(sum>=(1ll*ans*n)) return true;
        }
        return false;
    }
public:
    long long maxRunTime(int n, vector<int>& nums) {
        long long sum=nums[0];
        int sz=nums.size();
        for(int i=1;i<sz;++i){
            sum+=nums[i];
        }
        if(n==1) return sum;
        long long high=sum/n, low=1;
        while(low<high){
            long long mid=low+((high-low)/2)+1;
            if(valid(mid,nums,n,sz)) low=mid;
            else high=mid-1;
        }
        return low;
    }
};