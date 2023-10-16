static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();


class Solution {
public:
    vector<int> getRow(int rowIndex){
        vector<int>currRow;
        currRow={1};
        if(rowIndex==0) return currRow;
        currRow={1,1};
        if(rowIndex==1) return currRow;
        for(int i=2; i<=rowIndex; ++i){
            vector<int>temp;
            temp.push_back(1);
            for(int j=1;j<i;++j){
                temp.push_back((currRow[j-1]+currRow[j]));
            }
            temp.push_back(1);
            currRow=temp;
        }
        return currRow;
    }
};