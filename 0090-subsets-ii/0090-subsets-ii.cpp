static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
/*
class Solution {
    vector<vector<int>>ans;
    vector<int>temp;
    set<vector<int>>s;
    int n;
    void helper(int start,vector<int>&nums){
        if(s.find(temp)==s.end()) s.insert(temp);
        for(int i=start;i<n;++i){
            temp.push_back(nums[i]);
            helper(i+1,nums);
            temp.pop_back();
            //helper(i+1,nums);
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        helper(0,nums);
        for(vector<int>el:s){
            ans.push_back(el);
        }
        return ans;
    }
};*/







/*
class Solution {
    vector<vector<int>>ans;
    vector<int>temp;
    int n;
    void helper(int start,vector<int>&nums,bool prev_taken){
        if(start==n){
            ans.push_back(temp);
            return;
        }
        helper(start+1,nums,false);
        if(start>0 and nums[start]==nums[start-1] and prev_taken==false) return;
        temp.push_back(nums[start]);
        helper(start+1,nums,true);
        temp.pop_back();
        //helper(i+1,nums);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        helper(0,nums,false);
        return ans;
    }
};*/








class Solution {
    vector<vector<int>>ans;
    vector<int>temp;
    int n;
    void helper(int start,vector<int>&nums){
        ans.push_back(temp);
        for(int i=start;i<n;++i){
            if(i==start or nums[i]!=nums[i-1]){
                temp.push_back(nums[i]);
                helper(i+1,nums);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        helper(0,nums);
        return ans;
    }
};
