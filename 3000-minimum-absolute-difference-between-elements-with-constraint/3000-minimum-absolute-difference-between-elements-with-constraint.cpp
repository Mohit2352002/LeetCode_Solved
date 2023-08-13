static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int ans=INT_MAX, n=nums.size();
        // if(n<2 or x==0) return 0;
        // else if(n==2) return abs(nums[1]-nums[0]);
        set<int>s;
        for(int i=x;i<n;++i){
            s.insert(nums[i-x]);
             auto it=s.upper_bound(nums[i]);
            if(it!=s.end()) ans=min(ans,abs(nums[i]- *it));
            if(it!=s.begin()) ans=min(ans,abs(nums[i]- *prev(it)));
        }
        return ans;
    }
};