class Solution {
    vector<int>dp;
    int n;
    int helper(string &s, int i){
        if(s[i]=='0') return 0;
        if(i==n) return 1;
        if(dp[i]!=-1) return dp[i];
        string temp="";
        temp+=s[i];
        int ans=helper(s,i+1);
        if(i<n-1 && (s[i]=='1'||(s[i]=='2'&& s[i+1]<'7'))) ans+=helper(s,i+2);
        return dp[i]=ans;
    }
public:
    int numDecodings(string s) {
        if(s[0]=='0') return 0;
        n=s.size();
        dp.resize(n+1,-1);
        return helper(s,0);
    }
};