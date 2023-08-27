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





/*
class Solution {
    int dp[2001][2001];
    bool find(vector<int> &stones, int i, int k){
        if(i==stones.size()-1) return true;
        if(i>=stones.size()) return false;
        if(dp[i][k]!=-1) return dp[i][k]; 
        bool res = false;
        for(int next_jump=k-1;next_jump<=k+1;next_jump++){
            if(next_jump>0){
                int in=lower_bound(stones.begin(),stones.end(),stones[i]+next_jump)-stones.begin();
                if(in==stones.size() || stones[in]!=stones[i]+next_jump) continue;
                res=res||find(stones,in,next_jump);
            }
        }
        return dp[i][k]=res;
    }
public:  
    bool canCross(vector<int>& stones) {
        memset(dp,-1,sizeof(dp));
        return find(stones, 0, 0);
    }
};
*/





/*
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int N = stones.size();
        vector<vector<bool>> dp(N, vector<bool> (N+1, false));
        dp[0][1] = true;
        
        for(int i = 1; i < N; ++i){
            for(int j = 0; j < i; ++j){
                int diff = stones[i] - stones[j];
                if(diff > N || !dp[j][diff]) 
                    continue;
                
                if(i == N - 1) 
                    return true;
                
                dp[i][diff] = true;
                if(diff - 1 >= 0) dp[i][diff - 1] = true;
                if(diff + 1 <= N) dp[i][diff + 1] = true;
            }
        }
        return false;
    }
};
*/




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
                    if (step>0 && dp.count(stones[i]+step)) {
                        dp[stones[i] + step].insert(step);
                    }
                }
            }
        }
        return !dp[stones.back()].empty();
    }
};