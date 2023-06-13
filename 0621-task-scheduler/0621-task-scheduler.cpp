class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        if(tasks.size()==1) return 1;
        if(n==0) return tasks.size();
        int freq[26]={}, maxf=0;
        for(char c:tasks){
            ++freq[c-'A'];
            maxf=max(maxf,freq[c-'A']);
        }
        int gaps=(maxf-1)*(n+1);
        for(int el:freq){
            gaps-=min(maxf-1,el);
        }
        return tasks.size()+max(0,gaps);
    }
};