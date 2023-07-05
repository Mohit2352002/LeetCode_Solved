class Solution {
public:
    int singleNumber(vector<int>& nums) {

        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);

        int ones = 0;
        int twos = 0;

        for (const int &num : nums) {
            ones ^= (num & ~twos);
            twos ^= (num & ~ones);
        }

        return ones;
    }
};











/*
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < 32; i++) {
            int sum = 0;
            for(int j = 0; j < nums.size(); j++) {
                if(((nums[j] >> i) & 1) == 1) {
                    ++sum;
                    sum %= 3;
                }
            }
            if(sum != 0) ans |= sum << i;
        }
        return ans;
    }
};
*/