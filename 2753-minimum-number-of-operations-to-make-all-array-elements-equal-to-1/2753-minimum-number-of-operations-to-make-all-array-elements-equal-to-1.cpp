static auto _ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();


class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ones=count(nums.begin(),nums.end(),1);
        if(ones>0) return nums.size()-ones;
        int n=nums.size(),ans=INT_MAX;
        for(int i=0;i<n;++i){
            int curr_gcd=nums[i];
            for(int j=i+1;j<n;++j){
                curr_gcd=__gcd(curr_gcd,nums[j]);
                if(curr_gcd==1){
                    ans=min(ans,j-i+n-1);
                    break;
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};