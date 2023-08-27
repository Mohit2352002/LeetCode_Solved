static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
    void merge(vector<int>&nums, int start, int mid, int end){
        int i=start,j=mid+1;
        vector<int>temp;
        while(i<=mid and j<=end){
            if(nums[i]>=nums[j]) temp.push_back(nums[j++]);
            else temp.push_back(nums[i++]);
        }
        while(i<=mid) temp.push_back(nums[i++]);
        while(j<=end) temp.push_back(nums[j++]);
        int len=end-start+1;
        for(int k=0;k<len;++k){
            nums[start+k]=temp[k];
        }
    }
    void mergeSort(vector<int>&nums, int start, int end){
        if(start>=end) return;
        int mid=((start+end)>>1);
        mergeSort(nums,start,mid);
        mergeSort(nums,mid+1,end);
        merge(nums,start,mid,end);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        mergeSort(nums, 0, n-1);
        return nums;
    }
};