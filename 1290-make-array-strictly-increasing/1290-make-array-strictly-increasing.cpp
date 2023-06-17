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