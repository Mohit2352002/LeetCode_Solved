static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

/*
class Solution {
public:
    int check(int low) {
        int even=0,odd=0;
        while (low>0) {
            if (low%2==0)  ++even;
            else  ++odd;
            low/=10;
        }
        return (even==odd);
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {
        //low = (((low - 1)/k) + 1) * k;
        int addon=(k-(low%k))%k;
        low=low+addon;
        int count=0;
        while (low<=high) {
            count+=check(low);
            low+=k;
            if (low>=100000000) return count;
        }
        return count;
    }
};*/

       

class Solution{
    int dp[2][2][10][10][10][20];
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
    int solver(const string& s,const int& k,bool isStarted,bool isSmaller,int ind,int odd,int even,int rem){
        if(ind==s.size()) return (isStarted && odd==even && rem==0);
        int &ans=dp[isStarted][isSmaller][ind][odd][even][rem];
        if(ans!=-1) return ans;
        ans=0;
        int start=0,end=(isSmaller?9:(s[ind]-'0'));
        for(int i=start;i<=end;++i){
            bool new_isSmaller = isSmaller || i != end;
            bool new_isStarted = isStarted || i != 0;
            // int newOdd = odd + (new_isStarted && i%2 != 0);
            // int newEven = even + (new_isStarted && i%2 == 0);
            //bool new_isStarted=(!isStarted and i==0)?false:true;
            //bool new_isSmaller=(!isSmaller and i==end)?false:true;
            int newOdd=odd,newEven=even;
            if(new_isStarted){
                if(i&1) ++newOdd;
                else ++newEven;
            }
            int newRem=((10*rem)+i)%k;
            ans+=solver(s,k,new_isStarted,new_isSmaller,ind+1,newOdd,newEven,newRem);
        }
        return ans;
    }
public:
    int numberOfBeautifulIntegers(int low, int high, int k) {
        memset(dp,-1,sizeof dp);
        int right_ans=solver(to_string(high),k,false,false,0,0,0,0);
        memset(dp,-1,sizeof dp);
        int left_ans=solver(subtractOne(to_string(low)),k,false,false,0,0,0,0);
        return (right_ans-left_ans);
    }
};