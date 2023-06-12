class Solution {
    void helper(vector<string>&ans, int &n, int open, int close, string &curr){
        if(curr.size()==2*n){
            ans.push_back(curr);
            return;
        }
        if(open<n){
            curr+="(";
            helper(ans,n,open+1,close,curr); //can insert opening bracket
            curr.pop_back();
        }
        if(close<open){ 
            curr+=")";
            helper(ans,n,open,close+1,curr); //can insert closing bracket
            curr.pop_back();
        }
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
        string curr="";
        helper(ans,n,0,0,curr);
        return ans;
    }
};