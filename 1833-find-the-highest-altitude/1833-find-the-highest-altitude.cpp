class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int ans=0,curr_alt=0;
        for(int i=0;i<gain.size();++i){
            curr_alt+=gain[i];
            if(ans<curr_alt) ans=curr_alt;
        }
        return ans;
    }
};