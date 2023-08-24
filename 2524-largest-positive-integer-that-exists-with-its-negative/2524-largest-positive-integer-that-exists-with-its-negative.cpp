 static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int findMaxK(const vector<int>& nums) {
        bitset<1024> neg;
        for (int num : nums) {
            if (num < 0) neg[-num] = true;
        }
        int ans = -1;
        for (int num : nums) {
            if (num > ans && neg[num]) ans = num;
        }
        return ans;
    }
};