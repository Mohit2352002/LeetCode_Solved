 static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string convertToTitle(int num) {
        string ans="";
        while(num){
            --num;
            int first=num%26;
            ans+=('A'+first);
            num=num/26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};