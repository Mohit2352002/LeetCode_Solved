class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);

        int ones = 0;
        int twos = 0;

        for (const int num : nums) {
            ones ^= (num & ~twos);
            twos ^= (num & ~ones);
        }

        return ones;
    }
};