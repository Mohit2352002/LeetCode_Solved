class Solution {
    int maxHeight = 0;
    int n = 21;
    int dp[21][5002];

public:
    int helper(vector<int>&arr, int i, int firstSum,int secondSum){

        int diff = abs(firstSum-secondSum);
        if(i==n){
            if(diff==0){
               return 0;
            }
            return -1e9;
        }
        if(dp[i][diff]!=-1){
            return dp[i][diff];
        }
        int ans1 = arr[i]+ helper(arr,i+1,firstSum+arr[i],secondSum);
        int ans2 = helper(arr,i+1,firstSum,secondSum);
        int ans3 = arr[i]+helper(arr,i+1,firstSum,secondSum+arr[i]);
        return dp[i][diff] = max({ans1,ans2,ans3});
    }
    int tallestBillboard(vector<int>& rods) {

        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        this->n = rods.size();
        memset(dp, -1, sizeof(dp));
        int ans = helper(rods,0,0,0);
        if(ans<0) return 0;
        return ans/2;
    }
};










/*
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
*/