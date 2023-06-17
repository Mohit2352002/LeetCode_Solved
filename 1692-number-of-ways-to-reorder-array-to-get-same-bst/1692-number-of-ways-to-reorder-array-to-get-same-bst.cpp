/*
class Solution {

  typedef long long ll;
  ll MOD=1e9 + 7;

  vector<vector<ll>>PT; //Pascal Triangle to find ncr value

  ll solve(vector<int>&nums){

    if(nums.size()<3) return 1;

    vector<int>left_arr,right_arr;

    int root=nums[0];
    int n=nums.size();

    for(int i=1;i<n;++i){
      if(nums[i]>root) right_arr.push_back(nums[i]);
      else left_arr.push_back(nums[i]);
    }

    ll left_solve=solve(left_arr);
    ll right_solve=solve(right_arr);

    ll perm=PT[n-1][left_arr.size()]%MOD; // (n-1)c(r) 
    //possible combinations after fixing root and maintaing relative ordering of left and right arrays.
    
    return (perm*((right_solve*left_solve)%MOD))%MOD;
  }

public:
  int numOfWays(vector<int>& nums) {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n=nums.size();

    PT.resize(n+1);
    
    //Populating Pascal's Triangle
    PT[0]={1};
    PT[1]={1,1};
    for(int i=2;i<=n;++i){
      PT[i]=vector<ll>(i+1,1);
      for(int j=1; j<i;++j){
        PT[i][j]=(PT[i-1][j]+PT[i-1][j-1])%MOD; // ncr = (n-1)c(r) + (n-1)c(r-1);
      }
    }

    return solve(nums)-1;
  }
};
*/










class Solution {
public:
    const int mod = 1e9 + 7;
    long inverse(long num) {
        if (num == 1) return 1;
        return mod - mod / num * inverse(mod % num) % mod;
    }
    int dfs(vector<int>& nums) {
        int N = nums.size();
        if (N <= 2) return 1;
        vector<int> left, right;
        for (int i = 1; i < N; i++) {
            if (nums[i] < nums[0]) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }
        int a = left.size();
        int b = right.size();
        long res = 1;
        for (int i = b + 1; i <= a + b; i++) res = res * i % mod;
        for (int i = 1; i <= a; i++) res = res * inverse(i) % mod;
        return res * dfs(left) % mod * dfs(right) % mod;
    }
    int numOfWays(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        return dfs(nums) - 1;
    }
};
