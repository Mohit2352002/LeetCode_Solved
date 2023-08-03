static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
    unordered_map<int,vector<char>>mp;
    vector<string>ans;
    void helper(string &digits, int start,string &curr){
        if(start==digits.size()) ans.push_back(curr);
        for(char ch:mp[digits[start]-'0']){
            curr+=ch;
            helper(digits,start+1,curr);
            curr.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        char ch='a';
        for(int i=2;i<=9;++i){
            for(int j=0;j<3;++j) mp[i].push_back(ch++);
            if(i==7 or i==9) mp[i].push_back(ch++);
        }
        string temp="";
        helper(digits,0,temp);
        return ans;
    }
};