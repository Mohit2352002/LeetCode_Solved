static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

/*
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(nums[0]<nums[n-1]) return nums[0];
        int low=1,high=n-1;
        while(low<high){
            int mid=low+((high-low)/2);
            if(nums[mid]<nums[mid-1]) return nums[mid];
            else if(nums[mid]>nums[mid-1] and nums[mid]>nums[n-1]) low=mid+1;
            else high=mid-1;
        }
        return nums[low];
    }
};*/












class Solution {
public:
    int findMin(vector<int> &num) {
        int start=0,end=num.size()-1;
        
        while (start<end) {
            if (num[start]<num[end])
                return num[start];
            
            int mid = (start+end)/2;
            
            if (num[mid]>=num[start]) {
                start = mid+1;
            } else {
                end = mid;
            }
        }
        
        return num[start];
    }
};