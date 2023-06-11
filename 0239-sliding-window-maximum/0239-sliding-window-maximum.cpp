class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);

        int n=nums.size();
        if(n==1) return {nums[0]};

        deque<int>dq;
        vector<int>ans;

        for(int i=0;i<n;++i){

            if(!dq.empty() and dq.front()==i-k) dq.pop_front();

            while(!dq.empty() and nums[dq.back()]<nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);
            
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};