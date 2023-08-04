static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Trie {
    bool isWord=false;
    Trie* children[26]={};
public:
    Trie(){
    }
    
    void insert(string word) {
        Trie* curr=this;
        for(char ch:word){
            if(!curr->children[ch-'a']) curr->children[ch-'a']=new Trie();
            curr=curr->children[ch-'a'];
        }
        curr->isWord=true;
    }
    
    bool search(string word) {
        Trie* curr=this;
        for(char ch:word){
            if(!curr->children[ch-'a']) return false;
            curr=curr->children[ch-'a'];
        }
        return curr->isWord;
    }
    
    bool startsWith(string prefix) {
        Trie* curr=this;
        for(char ch:prefix){
            if(!curr->children[ch-'a']) return false;
            curr=curr->children[ch-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */