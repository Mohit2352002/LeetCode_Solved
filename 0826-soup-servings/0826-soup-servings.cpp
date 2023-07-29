static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
    map<pair<int,int>,double>mp;
    double helper(int a, int b){
        if(a<=0 and b<=0) return 0.5;
        if(a<=0) return 1.0;
        if(b<=0) return 0.0;
        if(mp.count({a,b})) return mp[{a,b}];
        double ans=0.0;
        ans+=helper(a-100,b);
        ans+=helper(a-75,b-25);
        ans+=helper(a-50,b-50);
        ans+=helper(a-25,b-75);
        return mp[{a,b}]=(double)ans*0.25;
    }
public:
    double soupServings(int n) {
        if(n>=5000) return 1.0;
        return helper(n,n);
    }
};