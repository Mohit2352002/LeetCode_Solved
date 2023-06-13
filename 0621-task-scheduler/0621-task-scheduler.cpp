class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int t_sz=tasks.size();
        if(t_sz==1) return 1;
        if(n==0) return tasks.size();
        unordered_map<char, int> counts;
        for(char t: tasks) 
            counts[t]++;
        priority_queue<int> pq;
        for(auto c: counts)
            pq.push(c.second);
        
        int result = 0;
        while(!pq.empty()){
            int time = 0;
            vector<int> tmp;
            for(int i = 0; i < n+1; ++i){
                if(!pq.empty()){
                    tmp.push_back(pq.top() - 1);
                    pq.pop();
                    time++;
                }
            }
            for(auto t: tmp)
                if(t) pq.push(t);
            result += pq.empty() ? time : n+1;
        }
        return result;
    }
};











/*
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int t_sz=tasks.size();

        if(t_sz==1) return 1;
        if(n==0) return t_sz;

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

        return t_sz+gaps;
    }
};
*/








/*
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        if(tasks.size()==1) return 1;
        if(n==0) return tasks.size();

        priority_queue<int> pq;
        int mp[26]={};

        for(char i:tasks){
            mp[i-'A']++;  // count the number of times a task needs to be done
        }   
        for(int i=0;i<26;++i){
            if(mp[i]) 
            pq.push(mp[i]);
        }

        int time=0; // stores the total time taken 
        while(!pq.empty()){
            vector<int>remain;
            int cycle=n+1;  // n+1 is the CPU cycle length, if n is the cooldown period then after a task A there will be n more tasks. Hence n+1.

            while(cycle and !pq.empty()){
                int max_freq=pq.top(); // the task at the top should be first assigned the CPU as it has highest frequency
                pq.pop();
                if(max_freq>1){ // task with more than one occurrence, the next occurrence will be done in the next cycle 
                    remain.push_back(max_freq-1); // add it to remaining task list
                }
                ++time; 
                --cycle; 
            }

            for(int count:remain){
                pq.push(count); 
            }
            if(pq.empty()) break; // if the priority queue is empty than all tasks are completed and we don't need to include the idle time
            time+=cycle; // this counts the idle time 
        }
        return time;
    }
};*/