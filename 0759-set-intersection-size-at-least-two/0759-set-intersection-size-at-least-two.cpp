class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& inv) {
        sort(inv.begin(),inv.end(),[&](vector<int>&a,vector<int>&b){
            if(a[1]==b[1]) return a[0]<b[0];
            return a[1]<b[1];
        });
        int last=inv[0][1],n=inv.size(),start=last-1;
        long long sz=2*n;
        for(int i=1;i<n;++i){
            if(last>inv[i][0]){
                if(start>=inv[i][0]) sz-=2;
                else{
                    --sz;
                    start=last;
                    last=inv[i][1];
                }
            }
            else if(last==inv[i][0]){
                --sz;
                start=last;
                last=inv[i][1];
            }else{
                last=inv[i][1];
                start=last-1;
            }
        }
        return (int)sz;
    }
};