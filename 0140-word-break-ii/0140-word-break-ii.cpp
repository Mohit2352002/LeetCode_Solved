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
};

