static auto _ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

/*
class Solution {
    vector<vector<int>>dp;
    int m,n;
    int lcs(string &a, string &b, int i, int j){
        if(i>=m or j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(a[i]==b[j]){
            return dp[i][j]=1+lcs(a,b,i+1,j+1);
        }
        else{
            return dp[i][j]=max(lcs(a,b,i+1,j),lcs(a,b,i,j+1));
        }
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        m=text1.size(),n=text2.size();
        dp.resize(m,vector<int>(n,-1));
        return lcs(text1,text2,0,0);
    }
};*/





/*
class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        int m=a.size(),n=b.size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[0][0]=(a[0]==b[0]);
        for(int i=1;i<m;++i) dp[i][0]=max(dp[i-1][0],a[i]==b[0]?1:0);
        for(int i=1;i<n;++i) dp[0][i]=max(dp[0][i-1],a[0]==b[i]?1:0);
        for(int i=1;i<m;++i){
            for(int j=1;j<n;++j){
                if(a[i]==b[j]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
};
*/





class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        int m=a.size(),n=b.size();
        if(m<n) return longestCommonSubsequence(b,a);
        vector<int>curr_dp(n+1,0),prev_dp(n+1,0);
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                if(a[i-1]==b[j-1]) curr_dp[j]=1+prev_dp[j-1];
                else curr_dp[j]=max(prev_dp[j],curr_dp[j-1]);
            }
            prev_dp=curr_dp;
        }
        return curr_dp[n];
    }
};