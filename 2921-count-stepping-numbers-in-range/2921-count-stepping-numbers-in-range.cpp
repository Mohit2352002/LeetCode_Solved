static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// class Solution {
//     int MOD=1e9+7;
//     int dp[2][2][10][101];
//     string subtractOne(string s){
//         reverse(s.begin(),s.end());
//         int first_non_zero=0;
//         while(s[first_non_zero]=='0') ++first_non_zero;
//         --s[first_non_zero];
//         for(int j=0;j<first_non_zero;++j) s[j]='9';
//         while(!s.empty() and s.back()=='0') s.pop_back();
//         if(s.empty()) s="0";
//         reverse(s.begin(),s.end());
//         return s;
//     }
//     int countValid(const string &s, bool isSmaller, bool isStarted, int ind, int prev){
//         if(ind==s.size()) return 1;
//         int &ans=dp[isStarted][isSmaller][prev][ind];
//         if(ans!=-1) return ans;
//         ans=0;
//         int start=0, end=isSmaller?9:(s[ind]-'0');
//         for(int j=start;j<=end;++j){
//             if(isStarted && abs(j-prev)!=1) continue;
//             bool new_isStarted=isStarted?true:(j!=0);
//             bool new_isSmaller=isSmaller?true:(j!=end);
//             ans=(ans+countValid(s,new_isSmaller,new_isStarted,ind+1,j))%MOD;
//         }
//         return ans;
//     }
// public:
//     int countSteppingNumbers(string low, string high) {
//         memset (dp, -1, sizeof(dp));
//         int right_ans=countValid(high,false,false,0,0);
//         memset (dp, -1, sizeof(dp));
//         int left_ans=countValid(subtractOne(low),false,false,0,0);
//         int ans=(right_ans-left_ans+MOD)%MOD;
//         return ans;
//     }
// };


class Solution {
    int MOD=1e9+7;
    int dp[2][2][10][101];
    string subtractOne(string s){
        int n=s.size();
        if(n==1 and s[0]=='0') return s;
        for(int i=n-1;i>=0;--i){
            if(s[i]=='0') s[i]='9';
            else{
                s[i]=s[i]-1;
                break;
            }
        }
        return s;
    }
    int helper(const string &s, bool isSmaller, bool isStarted,int ind, int prev){
        if(ind==s.size()) return 1;
        int &ans=dp[isStarted][isSmaller][prev][ind];
        if(ans!=-1) return ans;
        ans=0;
        int start=0,end=isSmaller?9:(s[ind]-'0');
        for(int i=start;i<=end;++i){
            if(isStarted and abs(i-prev)!=1) continue;
            bool new_isSmaller=(!isSmaller and i==end)?false:true;
            bool new_isStarted=(!isStarted and i==0)?false:true;
            ans=(ans+helper(s,new_isSmaller,new_isStarted,ind+1,i))%MOD;
        }
        return ans;
    }
public:
    int countSteppingNumbers(string low, string high) {
        memset(dp,-1,sizeof dp);
        int right_ans=helper(high,false,false,0,0);
        memset(dp,-1,sizeof dp);
        int left_ans=helper(subtractOne(low),false,false,0,0);
        int ans=(right_ans-left_ans+MOD)%MOD;
        return ans;
    }
};