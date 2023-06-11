class Solution {
public:
    string minWindow(string s, string p) {

        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);

        int s_sz=s.size(),p_sz=p.size();

        if(s_sz<p_sz) return "";

        int freq[60]={};
        for(char &ch:p) ++freq[ch-'A'];

        int start=0, end=0, unMatched=p_sz, winSize=INT_MAX, minStart=0;

        // for(;end<p_sz;++end){
        //     if(freq[s[end]-'A']>0) --unMatched;
        //     --freq[s[end]-'A'];
        // }

        // if(unMatched==0 and (end-start+1)<winSize){
        //     ans=s.substr(start,end-start+1);
        //     winSize=end-start+1;
        // }

        for(;end<s_sz;++end){

            if(freq[s[end]-'A']>0) --unMatched;
            --freq[s[end]-'A'];

            while(unMatched==0){
                if(winSize>(end-start+1)){
                    minStart=start;
                    winSize=end-start+1;
                }
                if(freq[s[start]-'A']>=0) ++unMatched;
                ++freq[s[start]-'A'];
                ++start;
            }
        }

        if(winSize==INT_MAX) return "";

        return s.substr(minStart,winSize);
    }
};