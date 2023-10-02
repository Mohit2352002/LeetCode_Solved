class Solution {
public:
    bool winnerOfGame(string colors) {
        int n=colors.size();
        if(n<3) return false;
        int countA=0,countB=0,contA=0,contB=0;
        for(int i=0;i<n;++i){
            if(colors[i]=='A'){
                countB+=max(0,contB-2);
                contB=0;
                ++contA;
            }else{
                countA+=max(0,contA-2);
                contA=0;
                ++contB;
            }
        }
        countB+=max(0,contB-2);
        countA+=max(0,contA-2);
        return countA>countB;
    }
};