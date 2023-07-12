class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int ans=0;
        for(int &num:nums) ans^=num;
        return ans;
    }
};