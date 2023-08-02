static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
    int n;
    vector<vector<int>>ans;
    vector<int>temp;
    void helper(vector<int>&nums,int start){
        ans.push_back(temp);
        for(int i=start;i<n;++i){
            temp.push_back(nums[i]);
            helper(nums,i+1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        n=nums.size();
        helper(nums,0);
        return ans;
    }
};