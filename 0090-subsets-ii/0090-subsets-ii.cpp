static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
    vector<vector<int>>ans;
    vector<int>temp;
    set<vector<int>>s;
    int n;
    void helper(int start,vector<int>&nums){
        if(s.find(temp)==s.end()) s.insert(temp);
        for(int i=start;i<n;++i){
            temp.push_back(nums[i]);
            helper(i+1,nums);
            temp.pop_back();
            //helper(i+1,nums);
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        helper(0,nums);
        for(vector<int>el:s){
            ans.push_back(el);
        }
        return ans;
    }
};