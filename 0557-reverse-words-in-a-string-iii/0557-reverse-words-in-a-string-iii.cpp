static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

/*
class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        if(n==1) return s;
        string temp="",ans="";
        for(int i=0;i<n;++i){
            if(s[i]==' ') continue;
            temp="";
            while(i<n and s[i]!=' '){
                temp+=s[i++];
            }
            reverse(temp.begin(),temp.end());
            ans+=temp;
            if(i!=n) ans+=' ';
        }
        return ans;
    }
};*/


class Solution {
public:
    string reverseWords(string s) {
        int lastSpaceIndex = -1;
        int len = (int)s.size();
        for (int strIndex = 0; strIndex <= len; ++strIndex) {
            if (strIndex == len || s[strIndex] == ' ') {
                int startIndex = lastSpaceIndex + 1;
                int endIndex = strIndex - 1;
                while (startIndex < endIndex) {
                    char temp = s[startIndex];
                    s[startIndex] = s[endIndex];
                    s[endIndex] = temp;
                    ++startIndex;
                    --endIndex;
                }
                lastSpaceIndex = strIndex;
            }
        }
        return s;
    };
};