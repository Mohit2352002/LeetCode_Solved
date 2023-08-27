static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();



/*
class Solution {
    int n;
    vector<vector<int>>dp;
    bool helper(vector<int>&nums, int i,int jump){
        if(i>=n-1 or jump==(nums[n-1]-nums[i])) return true;
        if(jump<=0 or jump>(nums[n-1]-nums[i])) return false;
        if(dp[i][jump]!=-1) return dp[i][jump];
        int ans=false;
        int low=i+1,high=n-1;
        while(low<=high){
            int mid=(low+((high-low)>>1));
            if(nums[mid]==(nums[i]+jump)){
                ans=(ans || helper(nums,mid,jump));
                ans=(ans || helper(nums,mid,jump+1));
                ans=(ans || helper(nums,mid,jump-1));
                break;
            }
            else if(nums[mid]>(nums[i]+jump)) high=mid-1;
            else low=mid+1;
        }
        return dp[i][jump]=ans;
    }
public:
    bool canCross(vector<int>& stones) {
        if(stones[1]!=1) return false;
        n=stones.size();
        dp.resize(n,vector<int>(n,-1));
        int ans=helper(stones,1,1);
        ans=(ans || helper(stones,1,2));
        return ans;
    }
};*/




class Solution {
public:
    bool canCross(std::vector<int>& stones) {
        int n = stones.size();
        unordered_map<int,unordered_set<int>> dp;
        for (int stone : stones) {
            dp[stone] = unordered_set<int>();
        }
        dp[0].insert(0);
        for (int i = 0; i < n; i++) {
            for (int k : dp[stones[i]]) {
                for (int step = k - 1; step <= k + 1; step++) {
                    if (step != 0 && dp.count(stones[i] + step)) {
                        dp[stones[i] + step].insert(step);
                    }
                }
            }
        }
        return !dp[stones.back()].empty();
    }
};