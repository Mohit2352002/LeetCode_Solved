static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
    unordered_map<string,bool>dict;
    int dp[301];
    bool helper(string &s, int start){
        if(start==s.size()){
            return true;
        }
        if(dp[start]!=-1) return dp[start];
        for(int i=start;i<s.size();++i){
            if(dict[s.substr(start,i-start+1)] and helper(s,i+1)) return dp[start]=true;
        }
        return dp[start]=false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for(string word:wordDict) dict[word]=true;
        memset(dp,-1,sizeof dp);
        return helper(s,0);
    }
};