static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>freq;
        for(int &el:arr1) ++freq[el];
        int i=0;
        for(int &el:arr2){
            while(freq[el]--) arr1[i++]=el;
        }
        for(auto el:freq){
            while(el.second-->0) arr1[i++]=el.first;
        }
        return arr1;
    }
};