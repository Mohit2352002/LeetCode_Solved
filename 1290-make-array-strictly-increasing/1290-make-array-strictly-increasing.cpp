class Solution {
public:
    vector<vector<int>> dp;
    int help(int ind,int last,vector<int>& arr1, vector<int>& arr2){
        if(ind==arr1.size()){
            return 0;
        }
    
        if(dp[ind][last]!=-1){
            return dp[ind][last];
        }

        int t=1e7;
        int lval;

        if(last==0){
            lval=arr1[ind-1];
        }else{
            lval=arr2[last-1];
        }

        if(arr1[ind]>lval){
            t=help(ind+1,0,arr1,arr2);
        }
        
        int it=upper_bound(arr2.begin(),arr2.end(),lval)-arr2.begin();
        if(it<arr2.size()){
            t=min(t,1+help(ind+1,it+1,arr1,arr2));
        }

        return dp[ind][last]=t;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {

        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        sort(arr2.begin(),arr2.end());

        dp.resize(arr1.size(),vector<int>(arr2.size()+1,-1));

        int t=min(help(1,0,arr1,arr2),1+help(1,1,arr1,arr2));

        if(t>1e5){
            return -1;
        }
        
        return t;
    }
};









/*
class Solution {
    map<pair<int,int>,int>mp;
    int solve(int idx, vector<int>& arr1, vector<int>& arr2, int prev){
        if(idx==arr1.size()) return 0;
        if(mp.find({idx,prev})!=mp.end()) return mp[{idx,prev}];
        int ans=1e9+1;
        if(arr1[idx]>prev){
            ans=min(ans,solve(idx+1,arr1,arr2,arr1[idx])); //no operation 
        }
        int it=upper_bound(arr2.begin(),arr2.end(),prev)-arr2.begin();
        if(it<arr2.size()){
            ans=min(ans,1+solve(idx+1,arr1,arr2,arr2[it]));
        }
        return mp[{idx,prev}]=ans;
    }
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        sort(arr2.begin(),arr2.end());
        int ans=solve(0,arr1,arr2,INT_MIN);
        if(ans==1e9+1) return -1;
        return ans;
    }
};
*/