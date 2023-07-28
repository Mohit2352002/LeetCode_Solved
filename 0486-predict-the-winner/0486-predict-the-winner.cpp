static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
    int dp[21][21];
    int helper(vector<int>&nums, int i, int j){
        if(i>j) return 0;
        if(i==j) return nums[i];
        if(dp[i][j]!=-1) return dp[i][j];
        int take_i=nums[i]+min(helper(nums,i+1,j-1),helper(nums,i+2,j));
        int take_j=nums[j]+min(helper(nums,i,j-2),helper(nums,i+1,j-1));
        return dp[i][j]=max(take_i,take_j);
    }
    
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        int player1_score= helper(nums,0,n-1), totalScore=0;
        for(int &el:nums) totalScore+=el;
        int player2_score=totalScore-player1_score;
        return player1_score>=player2_score;
    }
};