static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

  class Solution {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
        vector<string> result;
        void dfs(string vtex)
        {
            auto & edges = graph[vtex];
            while (!edges.empty())
            {
                string to_vtex = edges.top();
                edges.pop();
                dfs(to_vtex);
            }
            result.push_back(vtex);
        }
    public:
        vector<string> findItinerary(vector<vector<string>>& tickets) {
            for (auto e : tickets)
                graph[e[0]].push(e[1]);
            dfs("JFK");
            reverse(result.begin(), result.end());
            return result;
        }
    };

/*
class Solution {
    vector<string>path;
    int n;
    unordered_map<string,map<string,bool>>adj;
    bool dfs(const string &fromCity){
        path.push_back(fromCity);
        if(path.size()==(n+1)) return true;
        for(auto &toCity:adj[fromCity]){
            if(toCity.second){
                toCity.second=false;
                if(dfs(toCity.first)) return true;
                toCity.second=true;
            }
        }
        path.pop_back();
        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        n=tickets.size();
        for(auto &ticket:tickets){
            adj[ticket[0]][ticket[1]]=true;
        }
        string startCity="JFK";
        dfs(startCity);
        return path;
    }
};*/