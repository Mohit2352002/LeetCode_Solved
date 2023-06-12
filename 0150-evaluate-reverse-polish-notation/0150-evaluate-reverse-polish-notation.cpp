class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);

        if(tokens.size()==1) return stoi(tokens[0]);
        
        stack<int>s;

        for(string i:tokens){
            if(i=="+" or i=="-" or i=="*" or i=="/"){
                int ele2=s.top();
                s.pop();
                int ele1=s.top();
                s.pop();
                if(i=="+") s.push(ele1+ele2);
                if(i=="-") s.push(ele1-ele2);
                if(i=="*") s.push(ele1*ele2);
                if(i=="/"){
                    int x=ele1/ele2;
                    s.push(x);
                }
            }
            else{
                s.push(stoi(i));
            }
        }
        return s.top();
    }
};