class Solution {

    const int MOD = 1000000007;

    int helper(vector<int>& nums, int start, int &finish, int fuel, vector<vector<int>>&dp){
        
        if(fuel<0) return 0;
        if(dp[start][fuel]!=-1) return dp[start][fuel];

        int total=0;
        if(start==finish){
            ++total;
            if(fuel==0) return dp[start][0]=1;
        }
        if(fuel==0 and start!=finish) return 0;

        for(int i=0;i<nums.size();++i){
            if(nums[i]!=nums[start] and fuel>= abs(nums[start]-nums[i]) ){
                total=(total+ helper(nums,i,finish,fuel-abs(nums[start]-nums[i]),dp) )%MOD;
            }
        }

        return dp[start][fuel]=total;
    }

public:

    int countRoutes(vector<int>& nums, int start, int finish, int fuel) {
        
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);     

        if((abs(nums[start]-nums[finish])) > fuel) return 0;

        vector<vector<int>>dp(nums.size(),vector<int>(fuel+1,-1));

        return helper(nums,start,finish,fuel,dp);
    }
};
















/*
class Solution {
public:
    const int MOD = 1000000007;

    int helper(const vector<int>& locations, int city, int finish, int remainFuel, vector<vector<int>>& memo) {
        if (remainFuel < 0) {
            return 0;
        }
        
        if (memo[city][remainFuel] != -1) {
            return memo[city][remainFuel];
        }
        
        int total = city == finish ? 1 : 0;
        
        for (int nextCity = 0; nextCity < locations.size(); nextCity++) {
            if (nextCity != city && remainFuel >= abs(locations[nextCity] - locations[city])) {
                total = (total + helper(locations, nextCity, finish, remainFuel - abs(locations[nextCity] - locations[city]), memo)) % MOD;
            }
        }
        
        return memo[city][remainFuel] = total;
    }

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>> memo(n, vector<int>(fuel + 1, -1));
        return helper(locations, start, finish, fuel, memo);
    }
};
*/











/*
class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {  

        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);     
                 
        const int MOD = 1000000007;
        int n = locations.size();    
        
        vector<vector<int>> dp(n, vector<int>(fuel + 1, 0));
        for (int f = 0; f <= fuel; f++) {
            dp[finish][f] = 1;
        }
        
        // for each fuel, we calculate all cross between cities
        for (int f = 0; f <= fuel; f++) {
            for (int city = 0; city < n; city++) {            
                for (int nextCity = 0; nextCity < n; nextCity++) {               
                    if (nextCity != city && f >= abs(locations[nextCity] - locations[city])) {
                        dp[city][f] = (dp[city][f] + dp[nextCity][f - abs(locations[nextCity] - locations[city])]) % MOD;
                    }
                }
            }            
        }
        return dp[start][fuel];
    }
};
*/