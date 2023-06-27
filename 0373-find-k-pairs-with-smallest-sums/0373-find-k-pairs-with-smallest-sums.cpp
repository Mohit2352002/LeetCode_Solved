class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        vector<vector<int>> result;
        if (nums1.empty() || nums2.empty() || k <= 0)
            return result;
        auto comp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> min_heap(comp);
        min_heap.push({0, 0});
        while(k-- > 0 && min_heap.size())
        {
            auto idx_pair = min_heap.top(); min_heap.pop();
            result.push_back({nums1[idx_pair.first], nums2[idx_pair.second]});
            if (idx_pair.first + 1 < nums1.size())
                min_heap.push({idx_pair.first + 1, idx_pair.second});
            if (idx_pair.first == 0 && idx_pair.second + 1 < nums2.size())
                min_heap.push({idx_pair.first, idx_pair.second + 1});
        }
        return result;
    }
};










/*
class Solution {
    typedef pair<int,pair<int,int>> ppr;
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        vector<vector<int>>ans;
        int n=nums1.size(),m=nums2.size();
        priority_queue<ppr>maxh;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                int sum=nums1[i]+nums2[j];
                if(maxh.size()<k) maxh.push({sum,{nums1[i],nums2[j]}});
                else if(sum<maxh.top().first){
                    maxh.pop();
                    maxh.push({sum,{nums1[i],nums2[j]}});
                }
                else break;
            }
        }
        while(!maxh.empty()){
            ans.push_back({maxh.top().second.first,maxh.top().second.second});
            maxh.pop();
        }
        return ans;
    }
};*/