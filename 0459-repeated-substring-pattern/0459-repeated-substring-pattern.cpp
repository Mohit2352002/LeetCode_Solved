 static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
/*
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        for(int i=n/2;i>=1;--i){
            if(n%i==0){
                int times=n/i;
                string temp="";
                while(times--){
                    temp+=s.substr(0,i);
                }
                if(temp==s) return true;
            }
        }
        return false;
    }
};*/



class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t=s+s;
        if(t.substr(1,t.size()-2).find(s)!=-1) return true;
        return false;
    }
};