class Solution {
public:
    int removeDuplicates(vector<int>& nums){
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        if(nums.size()<3){
            return nums.size();
        }
        int i=2;
        for(int j=2;j<nums.size();j++){
            if(nums[i-2]!=nums[j]){
                nums[i]=nums[j];
                i++;
            }
        }
        return i;
    }
};