static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
    vector<vector<int>>ans;
    void helper(vector<int>&nums, int i, int n){
        if(i==n-1){
            ans.push_back(nums);
            return;
        }
        for(int j=i;j<n;++j){
            swap(nums[i],nums[j]);
            helper(nums,i+1,n);
            swap(nums[i],nums[j]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        helper(nums,0,nums.size());
        return ans;
    }
};