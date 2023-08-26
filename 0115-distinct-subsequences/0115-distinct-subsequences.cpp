static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();


/*
class Solution {
    vector<vector<int>>dp;
    int helper(string &s,string&t, int &n,int &sz, int i,int j){
        if(j==sz) return 1;
        if(i==n or n-i<sz-j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=helper(s,t,n,sz,i+1,j);
        if(s[i]==t[j]) ans+=helper(s,t,n,sz,i+1,j+1);
        return dp[i][j]=ans;
    }
public:
    int numDistinct(string s, string t) {
        int n=s.size(),sz=t.size();
        if(n<sz) return 0;
        if(n==sz) return s==t;
        dp.resize(n,vector<int>(sz,-1));
        return helper(s,t,n,sz,0,0);
    }
};*/


class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size(),sz=t.size();
        if(n<sz) return 0;
        if(n==sz) return s==t;
        vector<vector<unsigned int>>dp(sz+1,vector<unsigned int>(n+1,0));
        for(int j=0;j<=n;++j) dp[0][j]=1;
        for(int i=1;i<=sz;++i){
            for(int j=1;j<=n;++j){
                dp[i][j]= dp[i][j-1] + ((t[i-1]==s[j-1])? dp[i-1][j-1]:0);
            }
        }
        return dp[sz][n];
    }
};