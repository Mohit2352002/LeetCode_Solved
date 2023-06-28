class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        
        double ans=0;
        priority_queue<pair<double, int>>q;
        q.push({1, start});
        vector<pair<int, double>>adj[n];
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<double>v(n, 0);
        v[start]=1;
        while(!q.empty()){
            int pos=q.top().second;
            double cnt=q.top().first;
            q.pop();
            if(pos==end){return max(ans, cnt);}
            for(const auto& it: adj[pos]){
                if(cnt*it.second>v[it.first]){
                    v[it.first]=(double)cnt*it.second;
                    q.push({v[it.first], it.first});
                }
            }
        }
        
        return ans;
    }
};










/*
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {

        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);

        vector<unordered_map<int, double>> graph(n);
        for(int i = 0; i < edges.size(); ++i) {
            graph[edges[i][0]][edges[i][1]] = succProb[i];
            graph[edges[i][1]][edges[i][0]] = succProb[i];
        }
        //functionality wise, this array works as a visited array, 
        //only when we find a larger probability than the stored value
        //we will need to push next node into the queue
        
        // ans will be in dist[end]
        vector<double> dist(n, 0.0);///probability of reaching each node
        
        dist[start] = 1.0;//important intilization
        
        queue<int> q;
        q.push(start);
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            for (auto x : graph[curr]) {
                int node = x.first;
                double prob = x.second;
                double newProb = dist[curr] * prob;
                //ok, we can reach this node with a larger probability, try starting from it
                //a node might be pushed into the queue more than once
                 if (newProb > dist[node]) {
                    dist[node] = newProb;
                    q.push(node);
                }
            }
        }
        
        return dist[end];
    }
};*/