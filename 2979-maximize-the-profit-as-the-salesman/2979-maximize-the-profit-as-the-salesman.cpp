 static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
    vector<int>dp;
    int sz;
    int helper(vector<vector<int>>& offers, int i){
        if(i>=sz) return 0;
        if(dp[i]!=-1) return dp[i];
        int low=i+1,high=sz-1;
        while(low<=high){
            int mid=(low+((high-low)>>1));
            if(offers[i][1]<offers[mid][0]){
                high=mid-1;
            }else low=mid+1;
        }
        return dp[i]=max(helper(offers,i+1),offers[i][2]+helper(offers,low));
    }
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(),offers.end());
        sz=offers.size();
        dp.resize(sz+1,-1);
        return helper(offers,0);
    }
};