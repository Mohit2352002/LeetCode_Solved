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
        vector<int>ans(arr1.size());
        for(int &el:arr2){
            while(freq[el]--) ans[i++]=el;
        }
        for(auto el:freq){
            if(el.second==0) continue;
            while(el.second-->0) ans[i++]=el.first;
        }
        return ans;
    }
};