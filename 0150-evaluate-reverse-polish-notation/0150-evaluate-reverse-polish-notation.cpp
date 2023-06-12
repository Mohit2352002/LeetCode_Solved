class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int i=0,n=tokens.size();
        if(n==1) return stoi(tokens[0]);
        stack<int>sk;
        while(i<n){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="/" || tokens[i]=="*"){
                int a=sk.top();
                sk.pop();
                int b=sk.top();
                sk.pop();
                int c;
                if(tokens[i]=="+") c=a+b;
                else if(tokens[i]=="/") c=b/a;
                else if(tokens[i]=="-") c=b-a;
                else c=a*b;
                sk.push(c);
            }else sk.push(stoi(tokens[i]));
            ++i;
        }
        return sk.top();
    }
};