class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        if(nums.size()==1) return nums[0];
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int el:nums){
            pq.push(el);
            while(pq.size()>k) pq.pop();
        }
        return pq.top();
    }
};