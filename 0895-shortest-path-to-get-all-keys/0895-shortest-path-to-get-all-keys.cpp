class state{
    public:
    int keys, i, j;
    state(int keys, int i,int j){
        this->keys=keys;
        this->i=i;
        this->j=j;
    }
};
class Solution {

    int dir[4][2]={
            {-1,0},
        {0,-1},   {0,1},
             {1,0}
    };

public:
    int shortestPathAllKeys(vector<string>& grid) {

        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);

        //iterating the grid to find the starting position and total number of keys.
        int x=-1,y=-1, m=grid.size(), n=grid[0].size(), totalKeys=0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n; ++j){
                char ch=grid[i][j];
                if(ch=='@') x=i,y=j;
                else if (ch >= 'a' && ch <= 'f') totalKeys = max(ch - 'a' + 1, totalKeys);
            }
        }

        // bfs 
        queue<state *>q;
        unordered_map<string,bool>vis;
        state *start= new state(0,x,y);
        q.push(start);
        vis[to_string(0) + " " + to_string(x) + " " +to_string(y)] =true;
        //storing state so as we don't visit it again
        int steps=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz-- >0){
                state *curr=q.front();
                q.pop();
                if(curr->keys == ( (1 << totalKeys) -1) ) return steps;//all keys found
                for(auto &[dx,dy]: dir){
                    int nx=curr->i + dx, ny=curr->j + dy, keys=curr->keys;

                    //validate the new coordinate
                    if(nx>=0 and nx<m and ny>=0 and ny<n and grid[nx][ny]!='#'){
                        int ch=grid[nx][ny];

                        if(ch>='a' and ch<='f'){
                            //new key found, adding it to collection
                            keys = (keys | (1<<(ch-'a')));
                        }
                        if(ch>='A' and ch<='F' and ((keys>>(ch-'A'))&1)==0){
                            //lock but cooresponding key not present 
                            continue;
                        }
                        if(!vis[""+ to_string(keys)+ " "+ to_string(nx)+ " "+ to_string(ny)]){
                            vis[""+ to_string(keys)+" "+to_string(nx)+" "+to_string(ny)]=true;
                            q.push(new state(keys, nx, ny));
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};