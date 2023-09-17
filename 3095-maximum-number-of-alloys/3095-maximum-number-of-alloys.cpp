static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

#define ll long long
class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int low=0,high=1e9;
        while(low<=high){
            int itemsToMake=low+((high-low)>>1);
            bool makable=false;
            for(int machine=0;machine<k;++machine){
                ll curr_cost=0;
                for(int i=0;i<n;++i){
                    ll required_stock=(1ll*composition[machine][i]*itemsToMake)-stock[i];
                    if(required_stock>0) curr_cost+=required_stock*cost[i];
                    if(curr_cost>budget) break;
                }
                if(curr_cost<=budget){
                    makable=true;
                    break;
                }
            }
            if(makable){
                low=itemsToMake+1;
            }else{
                high=itemsToMake-1;
            }
        }
        return low-1;
    }
};