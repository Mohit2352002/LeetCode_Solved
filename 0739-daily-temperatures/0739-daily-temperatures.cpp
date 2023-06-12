class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int n=temperatures.size();
        if(n==1) return {0};
        stack<int>st;
        vector<int>ans(n,0);
        int i=0;
        while(i<n){
            while(!st.empty() and temperatures[st.top()]<temperatures[i]){
                ans[st.top()]=i-st.top();
                st.pop();
            }
            st.push(i);
            ++i;
        }
        return ans;
    }
};