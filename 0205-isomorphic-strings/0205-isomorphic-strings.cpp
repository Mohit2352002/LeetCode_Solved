static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        int n=s.size();
        unordered_map<int,int>mp1,mp2;
        for(int i=0;i<n;++i){
            if(mp1.find(s[i]-'a')!=mp1.end() and mp1[s[i]-'a']!=t[i]-'a') return false;
            else mp1[s[i]-'a']=t[i]-'a';
        }
        for(int i=0;i<n;++i){
            if(mp2.find(t[i]-'a')!=mp2.end() and mp2[t[i]-'a']!=s[i]-'a') return false;
            else mp2[t[i]-'a']=s[i]-'a';
        }
        return true;
    }
};