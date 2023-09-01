class Solution {
public:
    vector<int> countBits(int n) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        vector<int> ans(n+1,0);
        if(n==0) return ans;
        ans[1]=1;
        for(int i=2;i<=n;++i){
            if(i&1) ans[i]=ans[i-1]+1;
            else ans[i]=ans[i>>1];
        }
        return ans;
    }
};









/*
class Solution {
public:
    vector<int> countBits(int n) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        vector<int> ans(n+1,0);
        for(int i=0;i<=n;++i){
            ans[i]=__builtin_popcount(i);
        }
        return ans;
    }
};*/