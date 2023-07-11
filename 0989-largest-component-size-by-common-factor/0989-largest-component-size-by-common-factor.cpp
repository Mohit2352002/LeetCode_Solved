class Solution {
    vector<int>par;
    int find(int &child){
        if(par[child]==child) return child;
        return par[child]=find(par[child]);
    }
    void Union(int &num1,int num2){
        int p1=find(num1),p2=find(num2);
        par[p1]=p2;
    }
public:
    int largestComponentSize(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int n=nums.size(),max_el=n;
        for(int &num:nums) max_el=max(max_el,num);
        par.resize(max_el+1);
        for(int i=1;i<=max_el;++i) par[i]=i;
        for(int &num:nums){
            for(int factor=2;factor*factor<=num;++factor){
                if(num%factor==0){
                    //valid factor
                    Union(num,factor);
                    Union(num,num/factor);
                }
            }
        }
        unordered_map<int,int>cache;
        int ans=0;
        for(int &num:nums){
            ++cache[find(num)];
            ans=max(ans,cache[par[num]]);
        }
        return ans;
    }
};

/*
//Brute force Solution leading TLE
class Solution {
public:
    //TC O(n^2) //TLE
    //SC O(n*2)
    void dfs(int src,int& cnt,vector<int>& vis,vector<int> adj[]){
        vis[src]=1;cnt++;
        for(auto x:adj[src]){
            if(!vis[x]){
                dfs(x,cnt,vis,adj);
            }
        }
    }
    int largestComponentSize(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    if(__gcd(nums[i],nums[j])>1) {
                        adj[i].push_back(j);
                    }
                }
            }
        }
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                int cnt=0;
                dfs(i,cnt,vis,adj);
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};*/