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
        vector<int>mp(n+1,-1);
        for(int i=0;i<26;++i){
            if(freq[i]==0) continue;
            if(mp[freq[i]]==-1){
                mp[freq[i]]=i;
            }else{
                while(freq[i]>0 and mp[freq[i]]!=-1){
                    ++ans;
                    --freq[i];
                }
                if(freq[i]>0) mp[freq[i]]=i;
            }
        }
        return ans;
    }
};
//"aaabbbcc"
//a->3
//b->3
//c->2
//mp:   3->0.  2->1.  