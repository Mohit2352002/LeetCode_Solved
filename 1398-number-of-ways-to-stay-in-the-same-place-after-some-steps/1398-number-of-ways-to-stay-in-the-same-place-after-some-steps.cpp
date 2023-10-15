//Top Down (Memory Limit Exceeded can be avoided by setting arrLen to min of steps and arrLen)
/*
class Solution {
    int MOD=1e9+7;
    vector<vector<int>>dp;
    int helper(int idx, int steps, int &arrLen){
        if(idx<0 or idx>=arrLen) return 0;
        if(steps==0) return idx==0?1:0;
        if(dp[steps][idx]!=-1) return dp[steps][idx];
        int ans=helper(idx,steps-1,arrLen);
        ans+=helper(idx+1,steps-1,arrLen);
        ans%=MOD;
        ans+=helper(idx-1,steps-1,arrLen);
        return dp[steps][idx]=ans%MOD;
    }
public:
    int numWays(int steps, int arrLen){
        arrLen=min(steps,arrLen);
        dp.resize(steps+1, vector<int>(arrLen,-1));
        return helper(0,steps,arrLen);
    }
};*/




class Solution {
public:
    int numWays(int steps, int arrLen){
        int MOD=1e9+7;
        arrLen=min(steps/2 +1,arrLen);
        vector<vector<int>>dp(arrLen,vector<int>(steps+1,0));       
        dp[0][0]=1;
        for(int i=1;i<=steps;++i){
            for(int pos=0;pos<arrLen;++pos){
                dp[pos][i]=((((pos==arrLen-1)?0:dp[pos+1][i-1])+((pos==0)?0:dp[pos-1][i-1]))%MOD+dp[pos][i-1])%MOD;
            }
        }
        return dp[0][steps];
    }
};