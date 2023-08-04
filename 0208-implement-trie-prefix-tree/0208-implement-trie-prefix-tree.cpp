static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Trie {
    struct TrieNode{
        bool isWord;
        unordered_map<int,TrieNode*>children;
        TrieNode():isWord(false),children(unordered_map<int,TrieNode*>()){}
    };
    TrieNode*root;
public:
    Trie(){
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr=root;
        for(char ch:word){
            if(curr->children.find(ch) == curr->children.end() ){
                curr->children[ch]=new TrieNode();
            }
            curr=curr->children[ch];
        }
        curr->isWord=true;
    }
    
    bool search(string word) {
        TrieNode* curr=root;
        for(char ch:word){
            if(curr->children.find(ch) == curr->children.end() ){
                return false;
            }
            curr=curr->children[ch];
        }
        if(curr->isWord) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr=root;
        for(char ch:prefix){
            if(curr->children.find(ch) == curr->children.end() ){
                return false;
            }
            curr=curr->children[ch];
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