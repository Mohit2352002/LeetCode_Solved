static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size(),count=0,flips=0;
        for(int i=0;i<n;++i) if(nums[i]==0) ++count;
        if(k==1) return count;
        count=0;
        queue<int>q;
        for(int i=0;i<n;++i){
            if(((nums[i]==0) and ((count&1)==0)) or ((nums[i]==1) and ((count&1)==1))){
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
};