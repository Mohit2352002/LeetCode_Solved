class Solution {
public:
    vector<int> distributeCandies(int candies, int n) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        vector<int>ans(n,0);
        int count=0,i=0;
        while(candies>0){
            if(i==n) i=0;
            if(candies>=count+1){
                ans[i++]+=++count;
                candies-=count;
            }
            else{
                ans[i++]+=candies;
                candies=0;
            }
        }
        return ans;
    }
};