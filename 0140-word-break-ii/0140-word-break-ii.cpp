static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
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











/*
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
            for(string &el:subPart){
                if(el.size()==0) el=word;
                else el=word+" "+el;
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
};//*/






















struct TrieNode{
    bool isWord;
    unordered_map<char,TrieNode*>children;
    TrieNode(): isWord(false),children(unordered_map<char,TrieNode*>()){}
};
class Solution{
    vector<string>ans;
    TrieNode*root=new TrieNode();
    void solver(string &s, string sent,int start, int &n){
        if(start==n){
            ans.push_back(sent);
            return;
        }
        sent+=" ";
        TrieNode*curr=root;
        for(int j=start;j<n;++j){
            if(curr->children.find(s[j])==curr->children.end()){
                break;
            }
            curr=curr->children[s[j]];
            if(curr->isWord==true) solver(s,sent+s.substr(start,j-start+1),j+1,n);
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
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
        TrieNode*curr=root;
        for(int j=0;j<n;++j){
            if(curr->children.find(s[j])==curr->children.end()){
                break;
            }
            curr=curr->children[s[j]];
            if(curr->isWord==true) solver(s,s.substr(0,j+1),j+1,n);
        }
        return ans;
    }
};
