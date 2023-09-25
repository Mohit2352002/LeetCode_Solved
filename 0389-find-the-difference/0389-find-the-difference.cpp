static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    char findTheDifference(string s, string t) {
        int n=s.size();
        if(n==0) return t[0];
        for(int i=0;i<n;++i){
            t[i+1]+=(t[i]-s[i]);
        }
        return t[n];
    }
};