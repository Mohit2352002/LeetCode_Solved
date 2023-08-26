class Solution {
    vector<vector<string>>ans;
    vector<string>curr_ans;
    int n;
    vector<vector<int>>dp;
    bool isPalindrome(string &s, int i,int j){
        if(dp[i][j]!=-1) return dp[i][j];
        int start=i,end=j;
        while(start<end){
            if(s[start]!=s[end]) return dp[i][j]=0;
            start++;
            end--;
        }
        return dp[i][j]=1;
    }
    void helper(string &s, int i){
        if(i>=n){
            ans.push_back(curr_ans);
            return;
        }
        for(int j=i;j<n;++j){
            if(isPalindrome(s,i,j)){
                curr_ans.push_back(s.substr(i,j-i+1));
                helper(s,j+1);
                curr_ans.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        n=s.size();
        if(n==1) return {{s}};
        dp.resize(n,vector<int>(n,-1));
        helper(s,0);
        return ans;
    }
};




/*
class Solution {
    bool isPalindrome(string s,int i,int j,int dp[17][17]){
        if(dp[i][j]!=-1) return dp[i][j];
        int start=i,end=j;
        while(start<end){
            if(s[start]!=s[end]) return dp[i][j]=0;
            start++;
            end--;
        }
        return dp[i][j]=1;
    }
    void solve(string s,vector<string>&temp,int idx,vector<vector<string>>&ans, int dp[17][17]){
        if(idx>=s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<s.size();++i){
            if(isPalindrome(s,idx,i,dp)){
                temp.push_back(s.substr(idx,i-idx+1));
                solve(s,temp,i+1,ans,dp);
                temp.pop_back();
            }
        }
        return;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        int dp[17][17];
        vector<string>res;
        memset(dp,-1,sizeof(dp));
        solve(s,res,0,ans,dp);
        return ans;
    }
};
*/