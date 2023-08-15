static auto _ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n));
        for(int i=0;i<n;++i) dp[i][i]=1;
        int start=0,ansLen=1;
        for(int i=n-2;i>=0;--i){
            for(int j=i+1;j<n;++j){
                if(s[i]==s[j]){
                    if(j-i==1 or dp[i+1][j-1]){
                        dp[i][j]=1;
                        if(ansLen<(j-i+1)){
                            start=i;
                            ansLen=j-i+1;
                        }
                    }
                }
            }
        }
        return s.substr(start,ansLen);
    }
};