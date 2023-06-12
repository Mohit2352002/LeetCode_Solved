class Solution {
    void helper(vector<string>&ans, int &n, int open, int close, string curr){
        if(curr.size()==2*n){
            ans.push_back(curr);
            return;
        }
        if(open<n) helper(ans,n,open+1,close,curr+"("); //can insert opening bracket
        if(close<open) helper(ans,n,open,close+1,curr+")"); //can insert closing bracket
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        if(n==1) return {"()"};
        if(n==2) return {"(())","()()"};
        if(n==3) return {"((()))","(()())","(())()","()(())","()()()"};
        vector<string>ans;
        helper(ans,n,0,0,"");
        return ans;
    }
};