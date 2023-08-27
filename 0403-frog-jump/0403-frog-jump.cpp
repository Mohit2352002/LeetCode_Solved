static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
    int n;
    vector<vector<int>>dp;
    bool helper(vector<int>&nums, int i,int jump){
        if(i>=n-1 or jump==(nums[n-1]-nums[i])) return true;
        if(jump<=0 or jump>(nums[n-1]-nums[i])) return false;
        if(dp[i][jump]!=-1) return dp[i][jump];
        int ans=false;
        for(int j=i+1;j<n;++j){
            if(nums[j]==(nums[i]+jump)){
                ans=(ans || helper(nums,j,jump));
                ans=(ans || helper(nums,j,jump+1));
                ans=(ans || helper(nums,j,jump-1));
                break;
            }
        }
        return dp[i][jump]=ans;
    }
public:
    bool canCross(vector<int>& stones) {
        n=stones.size();
        if(stones[1]!=1) return false;
        dp.resize(n,vector<int>(n,-1));
        int ans=helper(stones,1,1);
        ans=(ans || helper(stones,1,2));
        return ans;
    }
};