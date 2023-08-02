class Solution {
    int n;
    vector<vector<int>>ans;
    void helper(int start, vector<int>&nums){
        if(start==(n-1)){
            ans.push_back(nums);
            return;
        }
        unordered_set<int>s;
        helper(start+1,nums);
        s.insert(nums[start]);
        for(int i=start+1;i<n;++i){
            if(s.find(nums[i])!=s.end()) continue;
            s.insert(nums[i]);
            swap(nums[i],nums[start]);
            helper(start+1,nums);
            swap(nums[i],nums[start]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        helper(0,nums);
        return ans;
    }
};
