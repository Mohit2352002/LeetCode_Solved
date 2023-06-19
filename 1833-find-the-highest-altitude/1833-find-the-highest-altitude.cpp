class Solution {
public:
    int largestAltitude(vector<int>& gains) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int ans=0,curr_alt=0;
        for(int gain:gains){
            curr_alt+=gain;
            ans=max(ans,curr_alt);
        }
        return ans;
    }
};