class Solution {
    int ans=0,n;
    void helper(int idx,vector<int>& count, int transfer, const vector<vector<int>> &req){
        if(idx==n){
            for(int i:count) if(i!=0) return;
            ans=max(ans,transfer);
            return;
        }
        if (transfer + (n - idx) <= ans) return;
        --count[req[idx][0]];
        ++count[req[idx][1]];
        helper(idx+1,count,transfer+1,req);
        ++count[req[idx][0]];
        --count[req[idx][1]];
        helper(idx+1,count,transfer,req); //not include;
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
