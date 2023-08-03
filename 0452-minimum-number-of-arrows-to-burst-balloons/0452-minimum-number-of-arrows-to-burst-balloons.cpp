class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[&](vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        });
        int count=1,n=points.size(),arrow=points[0][1];
        for(int i=1;i<n;++i){
            if(arrow>=points[i][0]) continue;
            else{
                ++count;
                arrow=points[i][1];
            }
        }
        return count;
    }
};



























/*
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int ans=1;
        int lastp=points[0][1];
        for(int i=0;i<points.size();++i){
            if(lastp<points[i][0]){
                ans++;
                lastp=points[i][1];
            }
            lastp=min(lastp,points[i][1]);
        }
        return ans;
    }
};

/*class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int ans=1,lastp=points[0][1];
        for(int i=0;i<points.size()-1;++i){
            if(lastp<points[i+1][0]){
                ans++;
                lastp=points[i+1][1];
            }
            else lastp=min(lastp,points[i+1][1]);
        }
        return ans;
    }
};
*/

/*bool static compare(vector<int> &A, vector<int> &B){
        return A[1] < B[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),compare);
        int ans=1,lastp=points[0][1];
        for(int i=0;i<points.size()-1;++i){
            if(lastp<points[i+1][0]){
                ans++;
                lastp=points[i+1][1];
            }
        }
        return ans;
    }
};*/
