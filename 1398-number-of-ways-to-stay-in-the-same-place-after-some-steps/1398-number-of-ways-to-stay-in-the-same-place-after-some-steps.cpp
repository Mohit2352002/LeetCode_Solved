static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

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



//bottom up
/*
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
};*/


//space optimised dp
class Solution {
public:
/*
    int numWays(int steps, int arrLen){
        int MOD=1e9+7;
        arrLen=min(steps/2 +1,arrLen);
        vector<int>dp(arrLen,0),prevdp(arrLen,0);       
        prevdp[0]=1;
        for(int i=1;i<=steps;++i){
            for(int pos=0;pos<arrLen;++pos){
                dp[pos]=((((pos==arrLen-1)?0:prevdp[pos+1])+((pos==0)?0:prevdp[pos-1]))%MOD+prevdp[pos])%MOD;
            }
            prevdp=dp;
        }
        return dp[0];
    }*/
    int numWays(int steps, int arrLen) {
        int sz = min(steps / 2 + 1, arrLen);
        vector<int> v1(sz + 2), v2(sz + 2);
        v1[1] = 1;
        while (steps-- > 0) {
            for (auto i = 1; i <= sz; ++i)
                v2[i] = ((long)v1[i] + v1[i - 1] + v1[i + 1]) % 1000000007;
            swap(v1, v2);
        }
        return v1[1];
    }
};