static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
    vector<vector<int>>ans;
    void helper(vector<int>&nums, int i, int &n){
        if(i==n){
            ans.push_back(nums);
            return;
        }
        for(int j=i;j<=n;++j){
            swap(nums[i],nums[j]);
            helper(nums,i+1,n);
            swap(nums[i],nums[j]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size()-1;
        helper(nums,0,n);
        return ans;
    }
};