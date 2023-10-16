static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();


class Solution {
public:
    vector<int> getRow(int rowIndex){
        vector<vector<int>>ans;
        ans.push_back({1});
        if(rowIndex==0) return {1};
        ans.push_back({1,1});
        if(rowIndex==1) return {1,1};
        for(int i=2; i<=rowIndex; ++i){
            vector<int>temp;
            temp.push_back(1);
            for(int j=1;j<i;++j){
                temp.push_back((ans[i-1][j-1]+ans[i-1][j]));
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans[rowIndex];
    }
};