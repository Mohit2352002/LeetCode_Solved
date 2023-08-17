static auto _ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();


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
};