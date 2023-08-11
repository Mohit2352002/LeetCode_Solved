static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low+((high-low)>>1);
            if(nums[mid]==target) return true;
            else if(nums[mid]==nums[high] and nums[low]==nums[mid]){
                ++low;
                --high;
            }else if(nums[mid]>=nums[low]){
                if(nums[mid]>=target and nums[low]<=target) high=--mid;
                else low=++mid;
            }else{
                if(nums[mid]<=target and nums[high]>=target) low=++mid;
                else high=--mid;
            }
        }
        return false;
    }
};