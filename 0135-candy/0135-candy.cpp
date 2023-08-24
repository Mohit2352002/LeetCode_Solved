static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size(),sum=0;
        vector<int>candies(n,1);
        for(int i=1;i<n;++i){
            if(ratings[i]>ratings[i-1]) candies[i]=candies[i-1]+1;
        }
        for(int i=n-2;i>=0;--i){
            if(ratings[i]>ratings[i+1] and candies[i]<=candies[i+1]) candies[i]=candies[i+1]+1;
            sum+=candies[i];
        }
        sum+=candies[n-1];
        return sum;
    }
};