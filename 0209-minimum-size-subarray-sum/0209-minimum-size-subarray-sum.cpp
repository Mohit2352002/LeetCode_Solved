class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        if(target==1) return 1;
        if(nums.size()==1) return target<=nums[0];
        int i=0,j=0,ans=INT_MAX,sum=0,n=nums.size();
        while(j<n and i<=j){
            sum+=nums[j++];
            if(sum>=target){
                while(sum>=target and i<=j){
                    ans=min(ans,j-i);
                    sum-=nums[i++];
                }
            }
        }
        if(ans==INT_MAX) return 0;
        return ans;
    }
};