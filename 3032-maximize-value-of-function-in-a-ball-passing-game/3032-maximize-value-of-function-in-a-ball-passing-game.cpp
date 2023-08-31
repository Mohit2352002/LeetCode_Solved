static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
#define ll long long int
class Solution {
    const int BITS=34;
public:
    long long getMaxFunctionValue(vector<int>& receiver, long long k) {
        int n=receiver.size();
        vector<vector<ll>>dst(BITS,vector<ll>(n));
        vector<vector<ll>>sum(BITS,vector<ll>(n));
        for(int j=0;j<n;++j){
            dst[0][j]=receiver[j];
            sum[0][j]=j+receiver[j];
        }
        for(int i=1;i<BITS;++i){
            for(int j=0;j<n;++j){
                dst[i][j]=dst[i-1][dst[i-1][j]];
                sum[i][j]=sum[i-1][dst[i-1][j]]+sum[i-1][j]-dst[i-1][j];
            }
        }
        vector<ll>finalDst(n),finalSum(n);
        for(int j=0;j<n;++j){
            finalDst[j]=j;
            finalSum[j]=j;
        }
        for(ll i=BITS-1;i>=0;--i){
            if(!((1LL<<i)& k)) continue;
            for(int j=0;j<n;++j){
                finalSum[j]=sum[i][finalDst[j]]+finalSum[j]-finalDst[j];
                finalDst[j]=dst[i][finalDst[j]];
            }
        }
        ll ans=0;
        for(auto i:finalSum) ans=max(ans,i);
        return ans;
    }
};