static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int removeDuplicates(vector<int>& nums){
        int n=nums.size();
        if(n<3){
            return nums.size();
        }
        int i=2;
        for(int j=2;j<n;++j){
            if(nums[i-2]!=nums[j]) nums[i++]=nums[j];
        }
        return i;
    }
};