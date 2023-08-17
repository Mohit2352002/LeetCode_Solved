static auto _ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();



class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        if(mat[0][0]!=0) mat[0][0]=m+n;
        for(int j=1;j<n;++j){
            if(mat[0][j]!=0) mat[0][j]=1+mat[0][j-1];
        }
        for(int i=1;i<m;++i){
            if(mat[i][0]!=0) mat[i][0]=1+mat[i-1][0];
        }
        for(int i=1;i<m;++i){
            for(int j=1;j<n;++j){
                if(mat[i][j]!=0) mat[i][j]=1+min(mat[i-1][j],mat[i][j-1]);
            }
        }
        for(int j=n-2;j>=0;--j){
            if(mat[m-1][j]!=0) mat[m-1][j]=min(mat[m-1][j],1+mat[m-1][j+1]);
        }
        for(int i=m-2;i>=0;--i){
            if(mat[i][n-1]!=0) mat[i][n-1]=min(mat[i][n-1],1+mat[i+1][n-1]);
        }
        for(int i=m-2;i>=0;--i){
            for(int j=n-2;j>=0;--j){
                if(mat[i][j]!=0) mat[i][j]=min(mat[i][j],1+min(mat[i+1][j],mat[i][j+1]));
            }
        }
        return mat;
    }
};