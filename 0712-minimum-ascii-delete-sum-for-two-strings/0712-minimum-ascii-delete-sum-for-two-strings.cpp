static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
    int helper(string &s1, string &s2, int &n, int &m, int i, int j,vector<vector<int>>&dp){
        if(i>=n and j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        else if(i>=n) return dp[n][j]=s2[j]+helper(s1,s2,n,m,i,j+1,dp);
        else if(j>=m) return dp[i][m]=s1[i]+helper(s1,s2,n,m,i+1,j,dp);
        if(s1[i]==s2[j]) return helper(s1,s2,n,m,i+1,j+1,dp);
        int take_i=s2[j]+helper(s1,s2,n,m,i,j+1,dp);//take i implies deleting s2[j];
        int take_j=s1[i]+helper(s1,s2,n,m,i+1,j,dp);;//take j implies deleting s1[i];
        return dp[i][j]=min(take_i,take_j);
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        return helper(s1,s2,n1,n2,0,0,dp);
    }
};