class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size()) return false;
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int k=s1.size(), freq[26]={}, unMatched=k;
        //memset(freq,0,sizeof freq);
        for(char ch:s1) ++freq[ch-'a'];
        int start=0,end=0;
        for(;end<k;++end){
            if(freq[s2[end]-'a']-- >0) --unMatched;
        }
        if(unMatched==0) return true;
        for(;end<s2.size();++end){
            if(freq[s2[start++]-'a']++ >=0) ++unMatched;
            if(freq[s2[end]-'a']-- >0) --unMatched;
            if(unMatched==0) return true;
        }
        return false;
    }
};