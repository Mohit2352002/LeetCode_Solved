class Solution {
    int ans, n;
    vector<int> rods;
    int dp[21][10003];

    int solve(int i, int diff) {
        if (i >= n) {
            if (diff == 0) return 0;
            return INT_MIN;
        }
        if(dp[i][diff + 5000] != -1) return dp[i][diff + 5000];
        int opt1 = solve(i + 1 , diff); //nothing
        int opt2 = rods[i] + solve(i + 1 , diff + rods[i]); //in_rod_1
        int opt3 = solve(i + 1 , diff - rods[i]); //in_rod_2
        return dp[i][diff + 5000] = max({opt1, opt2, opt3});
    }

public:

    int tallestBillboard(vector<int>& rods) {

        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);

        this->rods = rods;
        n = rods.size();

        memset(dp , -1 , sizeof(dp));

        int ans = solve(0, 0);

        if (ans < 0) return 0;
        return ans;
    }
};
