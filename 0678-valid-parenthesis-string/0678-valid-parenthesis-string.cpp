class Solution {
public:
    bool checkValidString(string s) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        stack<int>open,star;
        int n=s.size();
        for(int i=0;i<n;++i){
            if(s[i]=='('){
                open.push(i);
            }else if(s[i]==')'){
                if(!open.empty()) open.pop();
                else if(!star.empty()) star.pop();
                else return false;
            }else{
                star.push(i);
            }
        }
        while(!open.empty()){
            if(!star.empty() and open.top()<star.top()){
                open.pop();
                star.pop();
            }else return false;
        }
        return true;
    }
};