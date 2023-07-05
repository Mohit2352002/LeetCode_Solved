class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>mp;
        for(int &task:tasks){
            ++mp[task];
        }
        int ans=0;
        for(auto &el:mp){
            if(el.second==1) return -1;
            else if(el.second==2) ++ans;
            else{
                ans+=(ceil(1.0*el.second/3));
            }
        }
        return ans;
    }
};