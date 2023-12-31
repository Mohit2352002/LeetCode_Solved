static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
/*class Solution {
    vector<vector<int>>ans;
    void helper(int &n, int k, int i,vector<int>&temp){
        if(n-i+1<k or i>n or k<0) return;
        helper(n,k,i+1,temp);
        temp.push_back(i);
        if(k-1==0){
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        helper(n,k-1,i+1,temp);
        temp.pop_back();
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        helper(n,k,1,temp);
        return ans;
    }
};*/

class Solution {
    vector<vector<int>>ans;
    void helper(int &n, int k, int start,vector<int>&temp){
        if(k==0) ans.push_back(temp);
        if(start>n or k<0) return;
        for(int i=start;i<=n-k+1;++i){
            temp.push_back(i);
            helper(n,k-1,i+1,temp);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        helper(n,k,1,temp);
        return ans;
    }
};