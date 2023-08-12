static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

/*
class Solution {
    int n;
    vector<int>dp;
    bool is5power(int num){
        while(num!=1){
            if(num%5!=0) return false; 
            num/=5;
        }
        return true;
    }
    int helper(string s, int ind){
        if(s[ind]=='0') return 20;
        if(ind==n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int ans=20, val=0;
        for(int i=ind;i<n;++i){
            val=(val<<1)+(s[i]-'0');
            if(is5power(val))ans=min(ans, 1+helper(s,i+1));
        }
        return dp[ind]=ans;
    }
public:
    int minimumBeautifulSubstrings(string s) {
        if(s[0]=='0') return -1;
        n=s.size();
        dp.resize(n,-1);
        int ans=helper(s,0);
        if(ans>=20) return -1;
        else return ans;
    }
};*/
class Solution {
    bool is5power(int num){
        while(num!=1){
            if(num%5!=0) return false; 
            num/=5;
        }
        return true;
    }
    public:
    int minimumBeautifulSubstrings(string s) {
        if(s[0]=='0') return -1;
        int n=s.size();
        vector<int>dp(n+1,n+1);
        dp[0]=0;
        for(int i=0;i<n;++i){
            if(s[i]=='0') continue;
            int curr=0;
            for(int j=i;j<n;++j){
                curr=(curr<<1)+s[j]-'0';
                if(is5power(curr)) dp[j+1]=min(dp[j+1],1+dp[i]);
            }
        }
        return dp[n]>n ? -1 : dp[n];
    }
};
