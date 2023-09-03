class Solution {
    int length(int x){
        int d=0;
        while(x!=1){
            ++d;
            x/=2;
        }
        return d;
    }
    int lca(int a, int b){
        vector<int>patha,pathb;
        patha.push_back(a);
        pathb.push_back(b);
        while(a!=1){
            a/=2;
            patha.push_back(a);
        }
        while(b!=1){
            b/=2;
            pathb.push_back(b);
        }
        int x=patha.size(),y=pathb.size();
        int d=0;
        while(x>0 and y>0 and patha[--x]==pathb[--y]){
            ++d;
        }
        return d-1;
    }
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        int m=queries.size();
        vector<int>ans(m);
        for(int i=0;i<m;++i){
            int dx=length(queries[i][0]), dy=length(queries[i][1]);
            int dlca=lca(queries[i][0],queries[i][1]);
            ans[i]=dx+dy-(2*dlca)+1;
        }
        return ans;
    }
};