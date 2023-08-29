static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();



/*
class Solution {
public:
    int bestClosingTime(string s) {
        int n=s.size();
        vector<int>visits(n+1),absent(n+1);
        visits[n]=0;
        for(int i=n-1;i>=0;--i){
            visits[i]=(s[i]=='Y');
            if(i!=n-1) visits[i]+=visits[i+1];
        }
        absent[0]=0;
        for(int i=1;i<=n;++i){
            absent[i]=absent[i-1]+(s[i-1]=='N');
        }
        int penalty=INT_MAX, closing=0;
        for(int i=0;i<=n;++i){
            if(penalty>(absent[i]+visits[i])){
                closing=i;
                penalty=absent[i]+visits[i];
            }
        }
        return closing;
    }
};
*/





/*
class Solution {
public:
    int bestClosingTime(string s) {
        int n=s.size(), currPenalty=0,minPenalty,earliestHour=0;
        for(int i=0;i<n;++i) if(s[i]=='Y') ++currPenalty;
        minPenalty=currPenalty;
        for(int i=0;i<n;++i){
            if(s[i]=='Y') --currPenalty;
            else ++currPenalty;
            if(currPenalty<minPenalty){
                earliestHour=i+1;
                minPenalty=currPenalty;
            }
        }
        return earliestHour;
    }
};*/





class Solution {
public:
    int bestClosingTime(string &s) {
        int n=s.size(),currPenalty=0,minPenalty=0,rightTime=-1;
        for(int i=0;i<n;++i){
            currPenalty+=(s[i]=='Y')?-1:1;
            if(minPenalty>currPenalty){
                rightTime=i;
                minPenalty=currPenalty;
            }
        }
        return rightTime+1;
    }
};