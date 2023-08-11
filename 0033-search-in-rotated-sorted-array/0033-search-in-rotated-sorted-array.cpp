static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int n=nums.size();
//         int low=0,high=n-1;
//         while(low<=high){
//             int mid=low+((high-low)>>1);
//             if(nums[mid]==target) return mid;
//             if(nums[low]<=nums[mid]){
//                 if(nums[low]<=target and target<nums[mid]) high=mid-1;
//                 else low=mid+1;
//             }else{
//                 if(nums[mid]<target and target<=nums[high]) low=mid+1;
//                 else high=mid-1;
//             }
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low+((high-low)>>1);
            if(nums[mid]==target) return mid;
            else if(nums[mid]>=nums[low]){
                if(nums[mid]>=target and target>=nums[low]) high=--mid;
                else low=++mid;
            }else{
                if(nums[mid]<=target and target<=nums[high]) low=++mid;
                else high=--mid;
            }
        }
        return -1;
    }
};
        