static auto _ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>temp;
        for(int el:nums){
            if(temp.empty() or temp[temp.size()-1]<el) temp.push_back(el);
            else if(temp[temp.size()-1]==el) continue;
            else{
                auto up=lower_bound(temp.begin(),temp.end(),el);
                *up=el;
            }
        }
        return temp.size();
    }
};