/*
class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int i=n-1; i>=0; i--){
            dp[i][i] = 1;
            for (int j=i+1; j<n; j++){
                dp[i][j] = dp[i][j-1] + 1;
                for (int k=i; k<j; k++){
                    if (s[k] == s[j]) 
                        dp[i][j] = min(dp[i][j], dp[i][k] + (k+1<=j-1 ? dp[k+1][j-1] : 0));
                }
            }
        }
        return dp[0][n-1];
    }
};*/



class Solution {
public:
    vector<vector<int>> dp;
    int solve(string& s, int i, int j){
        if(i>j)             return 0;
        if(dp[i][j]!=0)     return dp[i][j];
        int x = i;
        while(x+1<=j && s[x]==s[x+1]) ++x;
        int ans = 1 + solve(s, x+1, j);
        for(int k = x+1; k<=j; ++k){
            if(s[k] == s[i])
                ans = min(ans,solve(s, x, k-1) + solve(s, k+1,j ));
        }
        return dp[i][j] = ans;
    }
    int strangePrinter(string s) {
        dp = vector<vector<int>> (s.size(), vector<int>(s.size(), 0));
        return solve(s, 0, s.size()-1);
    }
};