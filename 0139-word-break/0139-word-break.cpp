static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
/*
class Solution {
    unordered_map<string,bool>dict;
    int dp[301];
    bool helper(string &s, int start){
        if(start==s.size()) return true;
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
};//*/
















/*
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool>dict;
        int n=s.size();
        vector<bool>dp(n+1);
        for(string word:wordDict) dict[word]=true;
        dp[n]=true;
        for(int i=n-1;i>=0;--i){
            for(int j=i;j<n;++j){
                if((dict[s.substr(i,j-i+1)]==true) and (dp[j+1]==true)){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[0];
    }
};
*/


















/*
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        queue<int> validIndQ;
        vector<bool> checkedArr(n, false);
        validIndQ.push(-1); // search from 0

        while(!validIndQ.empty()) {
            int startInd = validIndQ.front() + 1;
            validIndQ.pop();
            // already checked
            if(checkedArr[startInd])
                continue;
            for(string _s : wordDict) {
                // too long
                if(startInd + _s.size() - 1 >= n)
                    continue;
                if(s.compare(startInd, _s.size(), _s) == 0) {
                    validIndQ.push(startInd + _s.size() - 1);
                    if(startInd + _s.size() - 1 == n-1)
                        return true;
                }
            }
            checkedArr[startInd] = true;
        }
        return false;
    }
};//*/











































struct TrieNode{
    bool isWord;
    unordered_map<char,TrieNode*>children;
    TrieNode(): isWord(false),children(unordered_map<char,TrieNode*>()){}
};
class Solution{
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        TrieNode*root=new TrieNode();
        for(string word:wordDict){
            TrieNode*curr=root;
            for(char ch:word){
                if( curr->children.find(ch) == curr->children.end() ){
                    curr->children[ch]=new TrieNode();
                }
                curr=curr->children[ch];
            }
            curr->isWord=true;
        }
        int n=s.size();
        vector<bool>dp(n+1,false);
        for(int i=0;i<n;++i){
            if(i==0 or dp[i-1]){
                TrieNode*curr=root;
                for(int j=i;j<n;++j){
                    if(curr->children.find(s[j])==curr->children.end()){
                        break;
                    }
                    curr=curr->children[s[j]];
                    if(curr->isWord==true) dp[j]=true;
                }
            }
        }
        return dp[n-1];
    }
};
