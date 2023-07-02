class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        bool timeOn[2001]={};
        //Sorting on the basis of 'End time'
        sort(tasks.begin(),tasks.end(),[](const auto &t1, const auto &t2){
            return t1[1]<t2[1];
        });
        for(auto &task:tasks){
            int &start=task[0], &end=task[1], duration=task[2];
            for(int i=start; i<=end; ++i) if(timeOn[i]) --duration;
            for(int i=end; duration>0; --i){
                if(timeOn[i]) continue;
                --duration;
                timeOn[i]=true;
            }
        }
        int countTimeOn=0;
        for(int i=0;i<2001;++i) countTimeOn+=timeOn[i];
        return countTimeOn;
    }
};