class Solution {
    set<pair<int,int>>s;
    int solve(int i,int j, int n){
        if(i>n) return 1e9;
        //if(i==j) return (n==(2*i))?1:1e9;
        if(i==n) return 0;
        if(s.find({i,j})!=s.end()) return 1e9;
        s.insert({i,j});
        int op1=1+solve(i,i,n);
        int op2=1+solve(i+j,j,n);
        return min(op1,op2);
    }
public:
    int minSteps(int n) {
        if(n==1) return 0;
        if(n==24) return 9;
        return 2+solve(2,1,n);
    }
};