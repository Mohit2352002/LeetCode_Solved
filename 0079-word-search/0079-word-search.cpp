static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
    int m,n,sz;
    int dir[5]={1,0,-1,0,1};
    bool helper(vector<vector<char>>& board, string &word, int i, int j, int k){
        if(k==sz) return true;
        if(i<0 or i>=m or j<0 or j>=n or word[k]!=board[i][j]) return false;
        bool ans=false;
        char ch=board[i][j];
        board[i][j]='*';
        for(int a=0;a<4;++a){
            ans=(ans or helper(board,word,i+dir[a],j+dir[a+1],k+1));
        }
        board[i][j]=ch;
        return ans;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size();
        n=board[0].size();
        sz=word.size();
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(board[i][j]==word[0] and helper(board,word,i,j,0)) return true;
            }
        }
        return false;
    }
};