static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int minDeletions(string s) {
        vector<int>freq(26,0);
        int n=s.size();
        for(int i=0;i<n;++i){
            ++freq[s[i]-'a'];
        }
        int ans=0;
        unordered_set<int>used;
        for(int i=0;i<26;++i){
            if(freq[i]==0) continue;
            if(used.find(freq[i])==used.end()){
                used.insert(freq[i]);
            }else{
                while(freq[i]>0 and used.find(freq[i])!=used.end()){
                    ++ans;
                    --freq[i];
                }
                if(freq[i]>0) used.insert(freq[i]);
            }
        }
        return ans;
    }
};