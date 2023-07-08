class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int n=weights.size();
        if(n<3 || k==1) return 0;
        vector<int>adjacentSums(n-1,0);
        long long minScore=0,maxScore=0;
        for(int i=0;i<n-1;++i){
            adjacentSums[i]=(weights[i]+weights[i+1]);
        }
        sort(adjacentSums.begin(),adjacentSums.end());
        for(int i=0;i<k-1;++i){
            minScore+=adjacentSums[i];
            maxScore+=adjacentSums[n-2-i];
        }
        return maxScore-minScore;
    }
};










/*
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<int> scores;
        for(int i = 1; i < n; ++i)
            scores.push_back(weights[i-1] + weights[i]);

        auto kth = scores.begin() + --k;
        nth_element(scores.begin(), kth, scores.end(), greater<int>());
        long long max = accumulate(scores.begin(), kth, (long long)0);

        kth = scores.begin() + k;
        nth_element(scores.begin(), kth, scores.end());
        long long min = accumulate(scores.begin(), kth, (long long)0);

        return max - min;
    }
};
*/