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
};