static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
    bool valid(int speed, vector<int>&nums, double time, int &n){
        double hours=ceil(1.0*nums[0]/speed);
        for(int i=1;i<n-1;++i){
            hours+=ceil(1.0*nums[i]/speed);
            if(hours>time) return false;
        }
        hours+=1.0*nums[n-1]/speed;
        if(hours>time) return false;
        return true;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size();
        if(n==1){
            if(ceil(1.0*dist[0]/hour)==(dist[0]/hour)+1) return dist[0]/hour;
            return ceil(dist[0]/hour);
        }
        if((floor(hour)==hour and n>hour) || n-1>floor(hour)) return -1;
        int low=1, high=1e7;
        while(low<high){
            int mid=low+((high-low)/2);
            if(valid(mid,dist,hour,n)) high=mid;
            else low=mid+1;
        }
        return low;
    }
};