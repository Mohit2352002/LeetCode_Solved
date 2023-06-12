class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);

        int n=position.size();
        vector<pair<int,int>>car;

        for(int i=0;i<n;++i){
            car.push_back({position[i],speed[i]});
        }

        sort(car.begin(),car.end());

        stack<float>st;

        int i=0;
        while(i<n){
            float time=((target-car[i].first)*1.0/car[i].second);
            while(!st.empty() and st.top()<=time){
                st.pop();
            }
            st.push(time);
            ++i;
        }

        return st.size();
    }
};