static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
/*
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size(),count=0,flips=0;
        for(int i=0;i<n;++i) if(nums[i]==0) ++count;
        if(k==1) return count;
        count=0;
        queue<int>q;
        for(int i=0;i<n;++i){
            if((nums[i]==(count&1)){
                if(i+k>n) return -1;
                ++count;
                ++flips;
                q.push(i+k-1);
            }
            if(q.front()==i){
                q.pop();
                --count;
            }
        }
        return flips;
    }
};//*/



class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size(),tot_flips=0,curr_flips=0;
        for(int i=0;i<n;++i){
            if(i>=k and nums[i-k]>1){
                --curr_flips;
                nums[i-k]-=2;
            }
            if((curr_flips&1)==nums[i]){
                if((i+k)>n) return -1;
                ++curr_flips;
                ++tot_flips;
                nums[i]+=2;
            }
        }
        return tot_flips;
    }
};