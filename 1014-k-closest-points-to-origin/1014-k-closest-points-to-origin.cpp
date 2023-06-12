class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        priority_queue<vector<int>>pq;
        for(auto el:points){
            int dist=(el[0]*el[0])+(el[1]*el[1]);
            pq.push({dist,el[0],el[1]});
            while(pq.size()>k) pq.pop();
        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            ans.push_back({pq.top()[1],pq.top()[2]});
            pq.pop();
        }
        return ans;
    }
};