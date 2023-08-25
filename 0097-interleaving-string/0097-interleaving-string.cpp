static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

/*
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
};*/

class Solution{
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length() != s1.length() + s2.length()) return false;
        bool table[s1.length()+1][s2.length()+1];
        for(int i=0; i<s1.length()+1; i++)
            for(int j=0; j< s2.length()+1; j++){
                if(i==0 && j==0) table[i][j] = true;
                else if(i==0) table[i][j]=(table[i][j-1] && s2[j-1] ==s3[i+j-1]);
                else if(j==0) table[i][j]=(table[i-1][j] && s1[i-1] ==s3[i+j-1]);
                else
                    table[i][j] = (table[i-1][j] && s1[i-1] == s3[i+j-1] ) || (table[i][j-1] && s2[j-1] == s3[i+j-1] );
            }
        return table[s1.length()][s2.length()];
    }
};