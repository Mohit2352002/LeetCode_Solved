class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int i = 0, j = 0,last_zero_idx = -1,result = 0;
        while(j < nums.size()) {
            if(nums[j] == 0) {
                i = last_zero_idx+1;
                last_zero_idx = j;
            }
            result = max(result, j-i);
            ++j;
        }
        return result;
    }
};











/*
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int i=0, j=0, count=0, ans=0, n=nums.size();
        while(j<n){
            if(nums[j]==0) ++count;
            while(count==2){
                if (nums[i++]==0) --count;
            }
            ans=max(ans,j-i);
            ++j;
        }
    return ans;
    }
};*/











/*
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        bool zero=false;
        int i=0,j=0, n=nums.size(),ans=0;
        if(n==1) return 0;
        while(j<n and i<=j){
            if(nums[j]==0){
                if(zero){
                    while(j<n and i<=j and zero){
                        if(nums[i++]==0){
                            zero=false;
                        }
                    }
                }
                zero=true;
            }
            ans=max(ans,j-i);
            ++j;
        }
        return ans;
    }
};
*/