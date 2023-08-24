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
    bool sumOfNumberAndReverse(int num) {
        if(num==0) return true;
        for(int i=num/2;i<num;++i){
            if(i+reverse(i)==num) return true;
        }
        return false;
    }
};