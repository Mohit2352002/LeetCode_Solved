static auto _ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();





/*
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
};*/





/*
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size(),start=0,ansLen=0;
        vector<vector<bool>>dp(n,vector<bool>(n));
        for(int diff=0;diff<n;++diff){
            for(int i=0;i<n-diff;++i){
                int j=i+diff;
                if(i==j) dp[i][j]=1;
                else if(j-i==1 and s[i]==s[j]) dp[i][j]=1;
                else if(s[i]==s[j] and dp[i+1][j-1]) dp[i][j]=1;
                else dp[i][j]=0;
                if(dp[i][j] and j-i+1>ansLen){
                    ansLen=j-i+1;
                    start=i;
                }
            }
        }
        return s.substr(start,ansLen);
    }
};
*/






class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size(),start=0,ansLen=1;
        for(int i=0;i<n;++i){
            //even substring
            int high=i+1,low=i;
            while(low>=0 and high<n and s[low]==s[high]){
                if(high-low+1>ansLen){
                    start=low;
                    ansLen=high-low+1;
                }
                ++high;
                --low;
            }
            //odd substring
            high=i+1,low=i-1;
            while(low>=0 and high<n and s[low]==s[high]){
                if(high-low+1>ansLen){
                    start=low;
                    ansLen=high-low+1;
                }
                ++high;
                --low;
            }
        }
        return s.substr(start,ansLen);
    }
};

