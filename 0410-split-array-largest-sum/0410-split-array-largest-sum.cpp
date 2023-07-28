static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
    bool helper(vector<int>&nums,int sum,int &k){
        int count=1,curr=0;
        for(int &el:nums){
            if(curr+el<=sum){
                curr+=el;
            }else{
                curr=el;
                ++count;
            }
            if(count>k) return true;
        }
        return count>k;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int hi=0,low=0;
        for(int &el:nums){
            hi+=el;
            low=max(low,el);
        }
        while(low<=hi){
            int mid=low+((hi-low)/2);
            if(helper(nums,mid,k)) low=mid+1;
            else hi=mid-1;
        }
        return low;
    }
};