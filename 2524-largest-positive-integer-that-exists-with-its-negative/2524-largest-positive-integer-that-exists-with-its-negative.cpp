class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans=-1,n=nums.size();
        unordered_set<int>us;
        for(int i=0;i<n;++i){
            if(us.find(-nums[i])!=us.end() and abs(nums[i])>ans){
                ans=abs(nums[i]);
            }
            us.insert(nums[i]);
        }
        return ans;
    }
};