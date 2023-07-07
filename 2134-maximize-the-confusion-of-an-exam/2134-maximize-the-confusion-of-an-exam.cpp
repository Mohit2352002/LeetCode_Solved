class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int i=0,j=0,n=s.length(),ans=0,temp=k;
        //converting Ts to Fs
        while(j<n and i<=j){
            if(s[j]=='T') ++j;
            else{
                while(k==0 and i<=j){
                    if(s[i++]=='F') k++;
                }
                if(k>0){
                    --k;
                    ++j;
                }
            }
            ans=max(ans,j-i);
        }
        i=0,j=0,k=temp;
        //converting Fs to Ts
        while(j<n and i<=j){
            if(s[j]=='F') ++j;
            else{
                while(k==0 and i<=j){
                    if(s[i++]=='T') k++;
                }
                if(k>0){
                    --k;
                    ++j;
                }
            }
            ans=max(ans,j-i);
        }
        return ans;
    }
};