static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
struct TrieNode{
    bool isWord;
    unordered_map<int,TrieNode*>children;
    TrieNode(): isWord(false),children(unordered_map<int,TrieNode*>()){}
};
/*
class Solution{
    void helper(string &s,  int start,string &curr){
        if(start>=s.size()) ans.push_back(curr);
        for(int i=start;i<s.size();++i){
            if(dict[s.substr(start,i-start+1)]){
                int sz=curr.size();
                if(sz!=0) curr+=" ";
                curr+=s.substr(start,i-start+1);
                helper(s,i+1,curr);
                curr.erase(sz,s.substr(start,i-start+1).size()+1);
            }
        }
    }
    unordered_map<string,bool>dict;
    vector<string>ans;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(string word:wordDict) dict[word]=true;
        int n=s.size();
        string temp="";
        helper(s,0,temp);
        return ans;
    }
};*/









class Solution{
    unordered_set<string>dict;
    unordered_map<int,vector<string>>dp;
    vector<string> helper(string s,int start){
        int n=s.size();
        if(start==n) return {""};
        if(dp.find(start)!=dp.end()) return dp[start];
        string word="";
        vector<string>subPart,completePart;
        for(int i=start;i<n;++i){
            word+=s[i];
            if(dict.count(word)==0) continue;
            subPart=helper(s,i+1);
            for(int j=0;j<subPart.size();++j){
                if(subPart[j].size()==0) subPart[j]=word;
                else subPart[j]=word+" "+subPart[j];
            }
            for(int j=0;j<subPart.size();++j) completePart.push_back(subPart[j]);
        }
        return dp[start]=completePart;
    }
public:
    vector<string>wordBreak(string s,vector<string>&wordDict){
        int n=s.size();
        for(string &word:wordDict) dict.insert(word);
        return helper(s,0);
    }
};
