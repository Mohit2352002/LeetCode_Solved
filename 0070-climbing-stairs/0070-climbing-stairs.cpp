static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 0) return 0;
        else if(n == 1) return 1;
        else if(n == 2) return 2;
        int one_step_before = 2,two_steps_before = 1,all_ways = 0;
        for(int i=3; i<=n; i++){
            all_ways = one_step_before + two_steps_before;
            two_steps_before = one_step_before;
            one_step_before = all_ways;
        }
        return all_ways;
    }
};