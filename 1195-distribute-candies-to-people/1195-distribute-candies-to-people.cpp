class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);

        vector<int> res(num_people, 0);

        double total = floor((-1 + sqrt(1 + 8ll * candies)) / 2);
        int round = floor(total / num_people);

        for (int i = 1; i <= num_people; i++){
            int first = i;
            int last = first + num_people * (round - 1);
            int inComplete = candies - (num_people+last) * (num_people + last - 1) / 2;
            res[i - 1]= (first+last)*round/2 + max(min(last+num_people, inComplete), 0);
        }
        return res;
    }
};









/*
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
*/