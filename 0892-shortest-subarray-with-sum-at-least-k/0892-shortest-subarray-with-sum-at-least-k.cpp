
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int N = A.size(), res = N + 1;
        vector<long>nums(N);
        nums[0]=A[0];
        deque<long> d;
        for (int i = 0; i < N; ++i) {
            if (i > 0)
                nums[i] = nums[i - 1]+A[i];
            if (nums[i] >= K)
                res = min(res, i + 1);
            while (d.size() > 0 && nums[i] - nums[d.front()] >= K){
                res = min((long)res, i - d.front());
                 d.pop_front();
            }
            while (d.size() > 0 && nums[i] <= nums[d.back()]){
                d.pop_back();
            }
            d.push_back(i);
        }
        return res <= N ? res : -1;
    }
};