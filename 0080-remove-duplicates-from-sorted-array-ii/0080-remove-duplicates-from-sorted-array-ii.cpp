class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int i=0;
        for(int &el:nums){
            if(i==0 or i==1 or nums[i-2]!=el) nums[i++]=el;
        }
        return i;
    }
};