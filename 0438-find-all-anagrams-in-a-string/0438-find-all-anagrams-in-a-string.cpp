class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int s_sz=s.size(),p_sz=p.size();
        if(s_sz<p_sz) return {};
        vector<int>ans;
        int freq[26]={};
        for(char ch:p) ++freq[ch-'a'];
        int start=0, end=0, unMatched=p_sz;
        for(;end<p_sz;++end){
            if(freq[s[end]-'a']>0) --unMatched;
            --freq[s[end]-'a'];
        }
        if(unMatched==0) ans.push_back(start);
        for(;end<s_sz;++end){
            if(freq[s[start]-'a']>=0) ++unMatched;
            ++freq[s[start]-'a'];
            ++start;
            if(freq[s[end]-'a']>0) --unMatched;
            --freq[s[end]-'a'];
            if(unMatched==0) ans.push_back(start);
        }
        return ans;
    }
};