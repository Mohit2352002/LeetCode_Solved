static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int,vector<int>>mp;
        int n=nums.size(),ans=1;
        for(int i=0;i<n;++i){
            mp[nums[i]].push_back(i);
        }
        for(auto el:mp){
            if(el.second.size()>1){
                vector<int>temp=el.second;
                int start=0,end=1,diff=0,count=1;
                while(end<temp.size()){
                    diff+=(temp[end]-temp[end-1]-1);
                    ++count;
                    while(diff>k){
                        --count;
                        diff-=(temp[start+1]-temp[start]-1);
                        ++start;
                    }
                    ++end;
                    ans=max(ans,count);
                }
            }
        }
        return ans;
    }
};