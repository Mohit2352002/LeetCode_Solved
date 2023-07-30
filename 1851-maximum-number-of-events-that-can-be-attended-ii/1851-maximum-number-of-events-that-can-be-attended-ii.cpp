static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int solve(vector<vector<int>>&dp, vector<vector<int>>& events, int n, int pos, int k){
        if(pos >= n || k == 0 || pos==-1) return 0;
        if(dp[pos][k] != -1) return dp[pos][k];
        // finding the next event which we can attend
        int left=pos+1,right=n-1,i=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(events[mid][0] > events[pos][1]){
                right=mid-1;
                i=mid;
            }else{
                left=mid+1;
            }
        }
       return dp[pos][k] = max(solve(dp, events, n, pos+1, k), events[pos][2] + solve(dp, events, n, i, k-1));
    }
    
    int maxValue(vector<vector<int>>& events, int k){
        int n = events.size();
        sort(events.begin(), events.end());
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return solve(dp, events, n, 0, k);
    }
};