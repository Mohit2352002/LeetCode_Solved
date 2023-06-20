class Solution {
public:
    int mctFromLeafValues(vector<int>& A) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        if(A.size()==2) return A[0]*A[1];
        int res = 0;
        vector<int> stack = {INT_MAX};
        for (int a : A) {
            while (stack.back() <= a) {
                int mid = stack.back();
                stack.pop_back();
                res += mid * min(stack.back(), a);
            }
            stack.push_back(a);
        }
        for (int i = 2; i < stack.size(); ++i) {
            res += stack[i] * stack[i - 1];
        }
        return res;
    }
};












/*
#include <algorithm>
using namespace std;
class Solution {
    int dp[41][41];
    int helper(int start,int end, vector<int>&nums){
        if(start>=end) return 0;
        if(dp[start][end]!=-1) return dp[start][end];
        long long ans=INT_MAX;
        for(int i=start;i<end;++i){
            int right_max=nums[max_element(nums.begin()+start,nums.begin()+i+1)-nums.begin()];
            int left_max=nums[max_element(nums.begin()+i+1,nums.begin()+end+1)-nums.begin()];
            long long curr_ans=(1ll*right_max*left_max)+helper(i+1,end,nums)+helper(start,i,nums);
            ans=min(ans,curr_ans);
        }
        return dp[start][end]=(int)ans;
    }
public:
    int mctFromLeafValues(vector<int>& arr) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n=arr.size();
        if(n==2) return arr[0]*arr[1];
        memset(dp,-1,sizeof(dp));
        return helper(0,n-1,arr);
    }
};*/