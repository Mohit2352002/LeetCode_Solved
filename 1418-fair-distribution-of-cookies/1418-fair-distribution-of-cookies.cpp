class Solution {
    int ans, k;
    vector<int>count;
    void helper(vector<int>& cookies, int cookieIndx){
        if(cookieIndx==cookies.size()){
            int maxel=0;
            for(int el:count) maxel=max(el,maxel);
            ans=min(ans,maxel);
            return;
        }
        for(int i=0;i<k;++i){
            if(i>0 and count[i]==count[i-1]) continue;
            count[i]+=cookies[cookieIndx];
            helper(cookies,cookieIndx+1);
            count[i]-=cookies[cookieIndx];
            if(count[i]==0) break;
        }
    }
public:
    int distributeCookies(vector<int>& cookies, int k) {

        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);

        int n=cookies.size();
        if(n==2) return max(cookies[0],cookies[1]);

        count.resize(k,0);
        ans=INT_MAX;
        this->k=k;
        helper(cookies,0);
        
        return ans;
    }
};