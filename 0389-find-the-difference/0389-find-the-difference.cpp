static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    char findTheDifference(string s, string t) {
        int n=t.size();
        if(n==1) return t[0];
        int freq[26]={};
        for(int i=0;i<n;++i){
            ++freq[t[i]-'a'];
            if(i!=(n-1)) --freq[s[i]-'a'];
        }
        for(int i=0;i<26;++i) if(freq[i]>0) return 'a'+i;
        return 'a';
    }
};