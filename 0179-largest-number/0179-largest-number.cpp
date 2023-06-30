class Solution {
    static bool cmp(string &a, string &b){
        return a+b>b+a;
    }
public:
    string largestNumber(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int n=nums.size();
        vector<string>snum(n);
        for(int i=0;i<n;++i) snum[i]=to_string(nums[i]);
        sort(snum.begin(),snum.end(),cmp);
        string ans="";
        for(int i=0;i<n;++i){
            ans=ans+snum[i];
        }
        int start=0;
        while(ans[start]=='0' and start<ans.size()-1) ++start;
        return ans.substr(start);
    }
};