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
};