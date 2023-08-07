static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
/*
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int n=nums[0].size(),m=nums.size(),low=0,hi=m-1;
        if(target<nums[0][0] or nums[m-1][n-1]<target) return false;
        while(low<=hi){
            int mid=low+((hi-low)>>1);
            if(nums[mid][0]>target) hi=mid-1;
            else if(nums[mid][0]<target) low=mid+1;
            else return true;
        }
        int i=low-1;
        low=0,hi=n-1;
        while(hi>=low){
            int mid=low+((hi-low)>>1);
            if(nums[i][mid]>target) hi=mid-1;
            else if(nums[i][mid]<target) low=mid+1;
            else return true;
        }
        return false;
    }
};*/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int n=nums[0].size(),m=nums.size(),low=0,hi=m*n-1;
        while(low<=hi){
            int mid=low+((hi-low)>>1);
            if(nums[mid/n][mid%n]<target) low=mid+1;
            else if(nums[mid/n][mid%n]>target) hi=mid-1;
            else return true;
        }
        return false;
    }
};

