static auto _ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        if(tasks.size()<2) return tasks.size();
        long long day=1;
        unordered_map<int,long long>mp;
        mp[tasks[0]]=day++;
        for(int i=1;i<tasks.size();i++){
            if(mp[tasks[i]]){
                day=max(space+mp[tasks[i]]+1,day);
                mp[tasks[i]]=day++;
            }
            else  mp[tasks[i]]=day++;
        }
        return day-1;
    }
};