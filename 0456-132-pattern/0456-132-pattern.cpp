class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size(),last=INT_MIN;
        stack<int>st;
        for(int i=n-1; i>=0; --i){
            if(nums[i]<last) return true;
            while(!st.empty() and st.top()<nums[i]){
                last=st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};