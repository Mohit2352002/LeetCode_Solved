static auto _ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

/*
class Solution {
    vector<vector<int>>dp;
    int helper(vector<int>&nums,int i,bool buy){
        if(i>=nums.size()) return 0;
        if(dp[buy][i]!=-1) return dp[buy][i];
        if(buy) return dp[buy][i]=max(helper(nums,i+1,false)-nums[i],helper(nums,i+1,true));
        else return dp[buy][i]=max(helper(nums,i+2,true)+nums[i],helper(nums,i+1,false));
    }
public:
    int maxProfit(vector<int>& prices) {
        dp.resize(2,vector<int>(prices.size(),-1));
        return helper(prices,0,true);
    }
};*/




/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int dp[n+2][2];
        for(int day=n+1;day>=0;--day){
            for(int buy=0;buy<=1;++buy){
                int &ans=dp[day][buy];
                if(day>=n) ans=0;
                else{
                    int ans1=dp[day+1][buy],ans2;
                    if(buy) ans2=-prices[day]+dp[day+1][0];
                    else ans2=prices[day]+dp[day+2][1];
                    ans=max(ans1,ans2);
                }
            }
        }
        return dp[0][1];
    }
};*/





class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(),sell=0,prev_sell=0,buy=INT_MIN,prev_buy;
        for(int price:prices){
            prev_buy=buy;
            buy=max(prev_sell-price,buy);
            prev_sell=sell;
            sell=max(prev_buy+price,sell);
        }
        return sell;
    }
};