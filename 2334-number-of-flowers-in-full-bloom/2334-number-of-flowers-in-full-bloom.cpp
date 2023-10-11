class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int>start,endd;
        int n=flowers.size(),sz=people.size();
        for(int i=0;i<n;++i){
            start.push_back(flowers[i][0]);
            endd.push_back(flowers[i][1]+1);
        }
        sort(start.begin(),start.end());
        sort(endd.begin(),endd.end());
        vector<int>ans(sz);
        for(int i=0;i<sz;++i){
            int bloomed=upper_bound(start.begin(),start.end(),people[i])-start.begin();
            int died=upper_bound(endd.begin(),endd.end(),people[i])-endd.begin();
            ans[i]=bloomed-died;
        }
        return ans;
    }
};