class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int sum = 0,n=jobs.size();
        for(int j:jobs) sum += j;
        if(k==1) return sum;
        else if (k == jobs.size()) return *max_element(begin(jobs), end(jobs));
        else if(n==2) return max(jobs[0],jobs[1]);
        sort(jobs.begin(),jobs.end(),greater<int>());
        int l = jobs[0], r = sum;
        while(l<r){
            int mid = (l+r)>>1;
            vector<int> worker(k,0);
            if(dfs(jobs,worker,0,mid))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
    bool dfs(vector<int>& jobs, vector<int>& worker, int step, int target){
        if(step>=jobs.size())
            return true;
        int cur = jobs[step];
        // assign cur to worker i 
        for(int i=0;i<worker.size();i++){
            if(worker[i] + cur <= target){
                worker[i] += cur;
                if(dfs(jobs,worker,step+1,target))
                    return true;
                worker[i] -= cur;
            }
            if(worker[i]==0)
                break;
        }
        return false;
    }
};









/*
class Solution {
    int ans, k;
    vector<int>count;
    void helper(vector<int>& jobs, int jobIndx){
        if(jobIndx==jobs.size()){
            int maxel=0;
            for(int el:count) maxel=max(el,maxel);
            ans=min(ans,maxel);
            return;
        }
        for(int i=0;i<k;++i){
            count[i]+=jobs[jobIndx];
            helper(jobs,jobIndx+1);
            count[i]-=jobs[jobIndx];
            if(count[i]==0) break;
        }
    }
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);

        int n=jobs.size();
        if(k==1) return accumulate(jobs.begin(), jobs.end(), 0);
        else if (k == jobs.size()) return *max_element(begin(jobs), end(jobs));
        else if(n==2) return max(jobs[0],jobs[1]);

        count.resize(k,0);
        ans=INT_MAX;
        this->k=k;
        helper(jobs,0);
        
        return ans;
    }
};*/