static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        int mp1[256]={0},mp2[256]={0};
        for(int i=0;i<n;++i){
            if(mp1[t[i]]!=mp2[s[i]]) return false;
            mp1[t[i]]=i+1;
            mp2[s[i]]=i+1;
        }
        return true;
    }
};