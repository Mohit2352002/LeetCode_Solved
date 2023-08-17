static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();


class Solution {
    vector<vector<int>>dp;
    bool helper(string &s1, string &s2, string &s3, int i,int j,int k){
        if(i>=s1.size() and j>=s2.size()) return true;
        else if(i>=s1.size()) return s2.substr(j)==s3.substr(k);
        else if(j>=s2.size()) return s1.substr(i)==s3.substr(k);
        else if(s1[i]!=s3[k] and s2[j]!=s3[k]) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        else if(s1[i]==s3[k] and s2[j]==s3[k]){
            return dp[i][j]=(helper(s1,s2,s3,i+1,j,k+1) or helper(s1,s2,s3,i,j+1,k+1));
        }else if(s1[i]==s3[k]) return dp[i][j]=helper(s1,s2,s3,i+1,j,k+1);
        else return dp[i][j]=helper(s1,s2,s3,i,j+1,k+1);
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        if(s1=="" and s2=="" and s3=="") return true;
        else if(s1=="" and s3==s2) return true;
        else if(s2=="" and s3==s1) return true;
        dp.resize(s1.size(),vector<int>(s2.size(),-1));
        return helper(s1,s2,s3,0,0,0);
    }
};