class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,sz=t.size(),n=s.size();
        for(int j=0;j<sz;++j){
            if(i==n) return true;
            if(t[j]==s[i]) ++i;
        }
        return i==n;
    }
};