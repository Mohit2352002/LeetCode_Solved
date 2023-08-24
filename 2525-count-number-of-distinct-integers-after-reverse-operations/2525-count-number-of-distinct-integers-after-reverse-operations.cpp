 static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
    int reverse(int n){
        int ans=0;
        while(n){
            ans=ans*10+(n%10);
            n/=10;
        }
        return ans;
    }
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int>us;
        int n=nums.size();
        for(int i=0;i<n;++i){
            if(us.find(nums[i])==us.end()) us.insert(nums[i]);
            int temp=reverse(nums[i]);
            if(us.find(temp)==us.end()) us.insert(temp);
        }
        return us.size();
    }
};