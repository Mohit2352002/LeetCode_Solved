 static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class DSU {
    vector<int>rank;
    vector<int>parent;
public:
    void start(int n){
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;++i) parent[i]=i;
    }
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }
    void Union(int x, int y){
        int parx=parent[x],pary=parent[y];
        if(parx==pary) return;
        if(rank[parx]>rank[pary]) parent[pary]=parx;
        else if(rank[parx]<rank[pary]) parent[parx]=pary;
        else{
            parent[pary]=parx;
            ++rank[parx];
        }
    }
};

class Solution {
    DSU ds;
    int N;
    int Krustal(vector<vector<int>>&vec, int skip_edge, int force_edge){
        ds.start(N);
        int sum=0,edgesConnected=0;
        if(force_edge!=-1){
            ds.Union(vec[force_edge][0],vec[force_edge][1]);
            sum+=vec[force_edge][2];
            ++edgesConnected;
        }
        for(int i=0;i<vec.size();++i){
            if(i==skip_edge) continue;
            int u=vec[i][0],v=vec[i][1],wt=vec[i][2];
            int paru=ds.find(u),parv=ds.find(v);
            if(paru==parv) continue;
            ds.Union(u,v);
            ++edgesConnected;
            sum+=wt;
        }
        if(edgesConnected!=N-1) return INT_MAX;
        return sum;
    }
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int E=edges.size();
        N=n;
        for(int i=0;i<E;++i) edges[i].push_back(i);
        sort(edges.begin(),edges.end(),[&](vector<int>&a,vector<int>&b){
            return a[2]<b[2];
        });
        int mspVal=Krustal(edges,-1,-1);
        vector<int>critical,pseudoCritical;
        for(int i=0;i<E;++i){
            if(Krustal(edges,i,-1)>mspVal){
                //skipping ith edge and weight becomes higher than mspVals
                //implies critical edge
                critical.push_back(edges[i][3]);
            }
            else if(Krustal(edges,-1,i)==mspVal) pseudoCritical.push_back(edges[i][3]);
        }
        return {critical, pseudoCritical};
    }
};