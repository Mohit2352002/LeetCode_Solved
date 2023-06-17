class Solution {
    map<pair<int,int>,int>mp;
    int solve(int idx, vector<int>& arr1, vector<int>& arr2, int prev){
        if(mp.find({idx,prev})!=mp.end()) return mp[{idx,prev}];
        if(idx>=arr1.size()) return 0;
        int ans1=1e9+1;
        if(arr1[idx]>prev){
            ans1=solve(idx+1,arr1,arr2,arr1[idx]); //no operation 
        }
        int ans2=1e9+1;
        auto it=upper_bound(arr2.begin(),arr2.end(),prev);
        if(it!=arr2.end()){
            int j=it-arr2.begin();
            ans2=1+solve(idx+1,arr1,arr2,arr2[j]);
        }
        return mp[{idx,prev}]=min(ans1,ans2);
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