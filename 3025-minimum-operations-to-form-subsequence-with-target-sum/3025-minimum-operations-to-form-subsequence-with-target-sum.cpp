static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        vector<int>power(32,0);
        int n=nums.size(),ans=0,j=32;
        for(int i=0;i<n;++i){
            ++power[int(log2(nums[i]))];
        }
        for(int i=0;i<31;++i){
            int bit=1<<i;
            if(target&bit){
                if(power[i]) --power[i];
                else j=min(j,i);
            }
            if(power[i] and j<i){
                --power[i];
                ans+=(i-j);
                j=32;
            }
            power[i+1]+=power[i]/2;
        }
        return (j<32)?-1:ans;
    }
};