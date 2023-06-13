/*
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        if(tasks.size()==1) return 1;
        if(n==0) return tasks.size();

    }
};
*/









class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int t_sz=tasks.size();
        if(t_sz==1) return 1;
        if(n==0) return tasks.size();
        int freq[26]={}, maxf=0;
        for(char c:tasks){
            ++freq[c-'A'];
            maxf=max(maxf,freq[c-'A']);
        }
        int gaps=(maxf-1)*(n+1);
        for(int el:freq){
            gaps-=min(maxf-1,el);
            if(gaps<=0) return t_sz;
        }
        return t_sz+max(0,gaps);
    }
};