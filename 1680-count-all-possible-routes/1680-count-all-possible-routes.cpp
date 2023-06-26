/*
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
};*/









#define modulo 1000000007
class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {

        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);      
        
        int m = locations.size();
        long long dp[m][fuel+1];
        for(int i=0;i<m;i++){
            for(int j=0;j<fuel+1;j++){
                dp[i][j]=-1;
            }
        }
          
          dp[start][fuel]=1;

    
            for(int j=fuel;j>=0;j--){
                for(int i=0;i<m;i++){
                    if(dp[i][j]!=-1){
                        for(int w=0;w<m;w++){
                            int remain = j-abs(locations[i]-locations[w]);
                            if(w!=i && remain>=0){
                                if(dp[w][remain]==-1) dp[w][remain]=dp[i][j];
                               else{ dp[w][remain]+=dp[i][j];
                                dp[w][remain]%=modulo;
                               }
                            }
                        }
                    }
                }
            }
        
         long long ans=0;
           for(int i=0;i<=fuel;i++){
               if(dp[finish][i]!=-1){
                   ans+=dp[finish][i];
                   ans%=modulo;
               }
           }


        return ans;
    }
};


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
};*/