static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
/*
class Solution {
public:
        int numMusicPlaylists(int N, int L, int K) {
        long dp[N + 1][L + 1], mod = 1e9 + 7;
        for (int i = K + 1; i <= N; ++i)
            for (int j = i; j <= L; ++j)
                if ((i == j) || (i == K + 1))
                    dp[i][j] = factorial(i);
                else
                    dp[i][j] = (dp[i - 1][j - 1] * i + dp[i][j - 1] * (i - K))  % mod;
        return (int) dp[N][L];
    }

    long factorial(int n) {
        return n ? factorial(n - 1) * n % (long)(1e9 + 7) : 1;
    }
};*/

class Solution {
    int mod=1e9+7;
    vector<vector<long long>>dp;
    int solve(int count_song, int count_unique, int &n, int &goal, int &k){
        if(count_song==goal) return count_unique==n;
        if(dp[count_song][count_unique]!=-1) return dp[count_song][count_unique];
        long long res=0;
        if(count_unique<n) res+=(1ll*(n-count_unique)*solve(count_song+1,count_unique+1,n,goal,k));
        if(count_unique>k) res+=(1ll*(count_unique-k)*solve(count_song+1,count_unique,n,goal,k));
        return dp[count_song][count_unique]=res%mod;
    }
public:
    int numMusicPlaylists(int n, int goal, int k) {
        if(n==1) return 1;
        dp.resize(goal+1,vector<long long>(n+1,-1));
        return solve(0,0,n,goal,k);
    }
};