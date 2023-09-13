static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();



/*
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size(),sum=0;
        vector<int>candies(n,1);
        for(int i=1;i<n;++i){
            if(ratings[i]>ratings[i-1]) candies[i]=candies[i-1]+1;
        }
        for(int i=n-2;i>=0;--i){
            if(ratings[i]>ratings[i+1] and candies[i]<=candies[i+1]) 
                candies[i]=candies[i+1]+1;
            sum+=candies[i];
        }
        sum+=candies[n-1];
        return sum;
    }
};*/



class Solution{
    int sum(int &n){
        return (n*(n+1))/2;
    }
public:
    int candy(vector<int>&ratings){
        int up=0,down=0,candies=0,n=ratings.size(),prevSlope=0;
        for(int i=1;i<n;++i){
            int currSlope=((ratings[i]>ratings[i-1])?1:((ratings[i]<ratings[i-1])?-1:0));
            if((currSlope>=0 and prevSlope<0) or (currSlope==0 and prevSlope>0)){
                candies+=(sum(up)+sum(down)+max(up,down));
                up=0;
                down=0;
            }
            if(currSlope>0) ++up;
            else if(currSlope<0) ++down;
            else ++candies;
            prevSlope=currSlope;
        }
        candies+=(sum(up)+sum(down)+max(up,down)+1);
        return candies;
    }
};