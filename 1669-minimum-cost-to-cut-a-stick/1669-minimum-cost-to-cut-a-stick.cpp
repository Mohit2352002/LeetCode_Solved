class Solution {
    int dp[102][102];
    int helper(int left, int right, vector<int>&cuts){
        if(left>=right-1) return 0;
        if(dp[left][right]!=-1) return dp[left][right];
        int cost=INT_MAX;
        for(int cuti=left+1;cuti<right;++cuti){
            cost=min(cost,cuts[right]-cuts[left]+helper(left,cuti,cuts)+helper(cuti,right,cuts));
        }
        return dp[left][right]=cost;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        memset(dp,-1,sizeof(dp));
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        return helper(0,cuts.size()-1,cuts);
    }
};
















// Recursion + Memoization
/*
class Solution {
    int dp[102][102];
    int helper(int left, int right,vector<int>&cuts){
        if(right - left <= 1) return 0;
        if(dp[left][right] != -1) return dp[left][right];
        int cost=1e9;
        for(int i=left+1;i<=right-1;++i){
            int left_cost=helper(left,i,cuts);
            int right_cost=helper(i,right,cuts);
            cost=min(cost, (cuts[right] - cuts[left])+left_cost+right_cost);
        }
        return dp[left][right]=cost;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        memset(dp,-1,sizeof(dp));
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        return helper(0,cuts.size()-1,cuts);
        }
};




//Tabulation (Bottom Up Approach)
class Solution {
public:
    int dp[102][102];
    int minCost(int n, vector<int>& cuts) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        memset(dp,0,sizeof(dp));
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        for(int left=cuts.size()-1; left>=0; --left){
            for(int right=left+1; right<cuts.size(); ++right){
                for(int i=left+1; i<right; ++i){
                    int curr_cost = (cuts[right] - cuts[left]) + dp[left][i] + dp[i][right];
                    dp[left][right] = min(dp[left][right] == 0 ? INT_MAX : dp[left][right], curr_cost);
                }
            }
        }
    return dp[0][cuts.size()-1];
    }
};*/