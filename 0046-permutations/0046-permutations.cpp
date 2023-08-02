static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
    void helper(vector<int>&nums, int i, int &n,vector<vector<int>>&ans){
        if(i==n){
            ans.push_back(nums);
            return;
        }
        helper(nums,i+1,n,ans);
        for(int j=i+1;j<=n;++j){
            swap(nums[i],nums[j]);
            helper(nums,i+1,n,ans);
            swap(nums[i],nums[j]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size()-1;
        helper(nums,0,n,ans);
        return ans;
    }
};