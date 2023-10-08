class Solution {
    int helper(int i, int j, vector<int>&a, vector<int>&b){
        if(i==a.size() or j==b.size()){
            return 0;
        }
        int op1=(a[i]*b[j])+helper(i+1,j+1,a,b);
        int op2=helper(i+1,j,a,b);
        int op3=helper(i,j+1,a,b);
        return max({op1,op2,op3});
    }
public:
    int maxDotProduct(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        vector<vector<int>> dp(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dp[i][j] = A[i] * B[j];
                if (i && j) dp[i][j] += max(dp[i - 1][j - 1], 0);
                if (i) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                if (j) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            }
        }
        return dp[n - 1][m - 1];
    }
};