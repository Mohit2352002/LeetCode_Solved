class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        unordered_map<int,int>mp;
        for(int &task:tasks){
            ++mp[task];
        }
        int ans=0;
        for(auto &el:mp){
            if(el.second==1) return -1;
            else{
                ans+=(ceil(1.0*el.second/3));
            }
        }
        return ans;
    }
};