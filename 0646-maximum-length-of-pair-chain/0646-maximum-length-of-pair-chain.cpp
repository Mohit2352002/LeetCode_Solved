static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();


/*
class Solution {
    int n;
    vector<int>dp;
    int helper(vector<vector<int>>& pairs, int i){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int low=i+1,high=n-1;
        while(low<=high){
            int mid=(low+((high-low)>>1));
            if(pairs[i][1]<pairs[mid][0]) high=mid-1;
            else low=mid+1;
        }
        return dp[i]=max(1+helper(pairs,low),helper(pairs,i+1));
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        n=pairs.size();
        dp.resize(n,-1);
        sort(pairs.begin(),pairs.end(),[&](vector<int>&a,vector<int>&b){
            if(a[0]==b[0]) return a[1]<b[1];
            return a[0]<b[0];
        });
        return helper(pairs,0);
    }
};*/



/*
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        vector<int>dp(n,1);
        sort(pairs.begin(),pairs.end(),[&](vector<int>&a,vector<int>&b){
            if(a[0]==b[0]) return a[1]<b[1];
            return a[0]<b[0];
        });
        int ans=1;
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                if(pairs[i][0]>pairs[j][1]) dp[i]=max(dp[i],1+dp[j]);
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};*/



class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end(),[&](vector<int>&a,vector<int>&b){
            return a[1]<b[1];
            if(a[1]==b[1]) return a[0]<b[0];
        });
        int res=1,end=pairs[0][1];
        for(int i=1;i<n;++i){
            if(pairs[i][0]>end){
                ++res;
                end=pairs[i][1];
            }
        }
        return res;
    }
};