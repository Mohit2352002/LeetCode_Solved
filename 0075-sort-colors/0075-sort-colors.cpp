static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0,mid=0,high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==1) mid++;
            else if(nums[mid]==0) swap(nums[mid++],nums[low++]);
            else swap(nums[high--],nums[mid]);
        }
    }
};