 static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();


class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,int>>pq;
        int n=s.size(),limit=(n+1)>>1;
        vector<int>freq(26,0);
        for(char &ch:s){ 
            ++freq[ch-'a'];
            if(freq[ch-'a']>limit) return "";
        }
        for(int i=0;i<26;++i) if(freq[i]) pq.push({freq[i],i});
        string ans="";
        while(pq.size()>=2){
            auto [count,curr]=pq.top();
            pq.pop();
            auto [count2,next]=pq.top();
            pq.pop();
            ans+=('a'+curr);
            ans+=('a'+next);
            --count;
            --count2;
            if(count) pq.push({count,curr});
            if(count2) pq.push({count2,next});
        }
        if(!pq.empty()) ans+='a'+pq.top().second;
        return ans;
    }
};