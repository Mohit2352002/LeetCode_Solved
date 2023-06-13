//m1
//c++ map can have vector as keys, while unordered_map can't.
#include<map>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();

        map<vector<int>, int> row2cnt;
        for(int i=0;i<n;i++)
            row2cnt[ grid[i] ]++;
        
        int cnt = 0;
        vector<int> col(n);
        for(int j=0;j<n;j++){
            for(int i=0;i<n;i++)
                col[i] = grid[i][j];
            
            //NOTE: inserts (key, 0) if not exist
            cnt += row2cnt[ col ];
        }

        return cnt;
    }
};









/*
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int count=0;
        if(grid.size()<2) return 1;
        for(int j=0;j<grid[0].size();j++){
            for(int k=0;k<grid.size();k++){
            if(grid[0][j]==grid[k][0]){
                for(int i=1;i<grid.size();i++){
                    if(grid[i][j]==grid[k][i]) { 
                        if(i==grid.size()-1) count++;
                    }
                    else break;
                }
            }
            }
        }
        return count;
    }
};
*/