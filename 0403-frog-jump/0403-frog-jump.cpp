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
        int low=i+1,high=n-1,flag=0;
        while(low<=high){
            int mid=(low+((high-low)>>1));
            if(nums[mid]==(nums[i]+jump)){
                low=mid;
                flag=1;
                break;
            }
            else if(nums[mid]>(nums[i]+jump)) high=mid-1;
            else low=mid+1;
        }
        if(flag){
            ans=(ans || helper(nums,low,jump));
            ans=(ans || helper(nums,low,jump+1));
            ans=(ans || helper(nums,low,jump-1));
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