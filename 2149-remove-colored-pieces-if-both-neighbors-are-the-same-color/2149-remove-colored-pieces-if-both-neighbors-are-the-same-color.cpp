static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool winnerOfGame(string colors) {
        int n=colors.size();
        if(n<3) return false;
        int countA=0,countB=0,contA=0,contB=0;
        for(int i=0;i<n;++i){
            if(colors[i]=='A'){
                if(contB>0){
                    countB+=max(0,contB-2);
                    contB=0;
                }
                ++contA;
            }else{
                if(contA>0){
                    countA+=max(0,contA-2);
                    contA=0;
                }
                ++contB;
            }
        }
        countB+=max(0,contB-2);
        countA+=max(0,contA-2);
        return countA>countB;
        /*
        int a = 0, b = 0;
        for(int i=1; i<n-1; ++i){
            if(s[i] == s[i-1] && s[i] == s[i+1]){
                if(s[i] == 'A') ++a;
                else ++b;
			}
        }
        return a>b;
        */
    }
};