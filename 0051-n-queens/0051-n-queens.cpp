static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
    vector<vector<string>>ans;
    vector<string>board;
    unordered_set<int>us_col,us_diag45,us_diag135;
    void helper(int n, int row){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int col=0;col<n;++col){
            if(isValid(row,col,n)) {
                board[row][col]='Q';
                us_col.insert(col);
                us_diag45.insert(row+col);
                us_diag135.insert(n-1+col-row);
                helper(n,row+1);
                board[row][col]='.';
                us_col.erase(col);
                us_diag45.erase(row+col);
                us_diag135.erase(n-1+col-row);
            }
        }
    }
    bool isValid(int row,int col,int n){
        /*
        for(int i=0;i<n;++i){
			// checking if there is a queen in the same column
		    if(board[i][col]=='Q') return false; 
		    // checking if there is a queen in the same diagonal (left to right)
		    if(row-i>=0 && col-i>=0 && board[row-i][col-i]=='Q') return false;
		    if(row-i>=0 && col+i<n && board[row-i][col+i]=='Q')  return false;
	    }*/
        if(us_col.find(col)!=us_col.end()) return false;
        if(us_diag45.find(row+col)!=us_diag45.end()) return false;
        if(us_diag135.find(n-1-row+col)!=us_diag135.end()) return false;
        return true;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        board.resize(n,string(n,'.'));
        helper(n,0);
        return ans;
    }
};