static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        int n=items.size();
        if(n==1) return items[0][0] +1;
        sort(items.begin(),items.end(),[&](vector<int>&a,vector<int>&b){
            return a[0]>b[0];
        });
        long long res = 0, cur = 0;
        vector<int> dup;
        unordered_set<int> seen;
        for (int i = 0; i < items.size(); ++i) {
            if (i < k) {
                if (seen.count(items[i][1])) {
                    dup.push_back(items[i][0]);
                }
                cur += items[i][0];
            } else if (seen.find(items[i][1]) == seen.end()) {
                if (dup.empty()) break;
                cur += items[i][0] - dup.back();
                dup.pop_back();
            }
            seen.insert(items[i][1]);
            res = fmax(res, cur + 1L * seen.size() * seen.size());
        }
        return res;
    }
};