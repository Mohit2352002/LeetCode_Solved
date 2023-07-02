class Solution {
    int ans=0,n;
    void helper(int idx,vector<int>& count, int transfers, const vector<vector<int>> &req){
        if(idx==n){
            for(int i:count) if(i!=0) return;
            ans=max(ans,transfers);
            return;
        }
        if (transfers + (n - idx) <= ans) return;
        helper(idx+1,count,transfers,req); //not include;
        --count[req[idx][0]];
        ++count[req[idx][1]];
        helper(idx+1,count,transfers+1,req);
        ++count[req[idx][0]];
        --count[req[idx][1]];
    }
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        this->n=requests.size();
        vector<int>count(n,0);
        helper(0,count,0,requests);
        return ans;
    }
};
