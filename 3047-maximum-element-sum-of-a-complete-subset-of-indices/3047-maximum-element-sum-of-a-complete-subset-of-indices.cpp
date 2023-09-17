static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

#define ll long long
class Solution {
public:
    long long maximumSum(vector<int>& nums) {
        int n=nums.size();
        ll result=0;
        for(int i=1;i<=n;++i){
            ll sum=0;
            for(int j=1;j<=100;++j){
                int ind=j*j*i;
                if(ind>n) break;
                sum+=nums[ind-1];
            }
            result=max(result,sum);
        }
        return result;
    }
};