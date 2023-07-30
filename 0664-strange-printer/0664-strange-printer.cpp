class Solution {
public:
    int strangePrinter(string s) {
        int n=s.length();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(i==j)dp[i][j]=1;
                else{
                    int temp=dp[i][j-1]+1,m;
                    for(m=j-1;m>=i;m--)
                        if(s[m]==s[j]){
                            if(m>0&&temp>dp[i][m-1]+dp[m][j-1])temp=dp[i][m-1]+dp[m][j-1];
                            else if(m==0) temp=dp[0][j-1];//for special cases
                        }
                    dp[i][j]=temp;
                }
            }
        }
        return dp[0][n-1];
    }
};