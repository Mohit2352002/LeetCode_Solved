class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);

        priority_queue<pair<float,int>> minHeap;
        vector<vector<int>> result;

        for(int i = 0; i < points.size(); ++i){
            float distance = sqrt((points[i][0] * points[i][0]) + (points[i][1] * points[i][1]));
            minHeap.push(make_pair(distance,i));
            if(minHeap.size() > k)
                minHeap.pop();
        }

        while(k--){
            result.push_back(points[minHeap.top().second]);
            minHeap.pop();
        }

        return result;
    }
};