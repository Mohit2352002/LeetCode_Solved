class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int curr_alt=gain[0], ans=max(0,curr_alt), n=gain.size();
        for(int i=1;i<n;++i){
            curr_alt+=gain[i];
            if(ans<curr_alt) ans=curr_alt;
        }
        return ans;
    }
};