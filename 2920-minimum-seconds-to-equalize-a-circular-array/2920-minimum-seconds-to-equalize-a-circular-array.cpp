static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;++i){
            mp[nums[i]].push_back(i);
        }
        int max_gap_for_min_ans=INT_MAX;
        for(auto el:mp){
            int len=el.second.size();
            if(len==1){
                max_gap_for_min_ans=min(max_gap_for_min_ans,n-1);
                continue;
            }else{
                int curr_max_gap=el.second[1]-el.second[0]-1;
                for(int i=1;i<len;++i){
                    curr_max_gap=max(curr_max_gap,el.second[i]-el.second[i-1]-1);
                }
                curr_max_gap=max(curr_max_gap,n-1-el.second[len-1]+el.second[0]);
                max_gap_for_min_ans=min(max_gap_for_min_ans,curr_max_gap);
            }
        }
        return (max_gap_for_min_ans+1)/2;
    }
};