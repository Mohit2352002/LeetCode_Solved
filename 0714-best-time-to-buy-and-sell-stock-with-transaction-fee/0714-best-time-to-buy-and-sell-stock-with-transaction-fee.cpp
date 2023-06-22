class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {

        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);

        int n=prices.size();

        if(n==1) return 0;
        else if(n==2) return max(0, prices[1]-prices[0]-fee);

        vector<vector<int>>dp(n,vector<int>(2,0));
        dp[0][0]=-(prices[0]+fee);

        for(int i=1;i<n;++i){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]-(prices[i]+fee));
            dp[i][1]=max(dp[i-1][0]+prices[i],dp[i-1][1]);
        }
        
        return dp[n-1][1];
    }
};