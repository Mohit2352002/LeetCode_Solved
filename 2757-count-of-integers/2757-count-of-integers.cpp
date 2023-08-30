static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
    const int MOD = 1e9+7;
    int dp[2][23][401];
    string subtractOne(string s){
        int n=s.size();
        if(n==1 and (s[0]=='0' or s[0]=='1')) return "0";
        while(n--){
            if(s[n]=='0') s[n]='9';
            else{
                s[n]=s[n]-1;
                break;
            }
        }
        return s;
    }
    int solver(string s, int minSum, int maxSum, bool isSmaller, int ind, int sum){
        if(ind==s.size()) return (sum<=maxSum and sum>=minSum);
        int &ans=dp[isSmaller][ind][sum];
        if(ans!=-1) return ans;
        ans=0;
        if(sum>maxSum) return ans;
        int start=0,end=(isSmaller?9:(s[ind]-'0'));
        for(int i=start;i<=end;++i){
            bool new_isSmaller=(isSmaller || (i!=end));
            int newSum=sum+i;
            ans=(ans+solver(s,minSum,maxSum,new_isSmaller,ind+1,newSum))%MOD;
        }
        return ans;
    }
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp,-1,sizeof dp);
        int rightAns=solver(num2,min_sum,max_sum,false,0,0);
        memset(dp,-1,sizeof dp);
        int leftAns=solver(subtractOne(num1),min_sum,max_sum,false,0,0);
        return (rightAns-leftAns+MOD)%MOD;
    }
};
