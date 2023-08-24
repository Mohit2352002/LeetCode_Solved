 static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
    void processOneWordLine(vector<string>&currLine,vector<string>&ans,int &currLen,int &maxWidth){
        string currans=currLine[0];
        int spaces=(maxWidth-currLen);
        for(int i=0;i<spaces;++i){
            currans+=" ";
        }
        ans.push_back(currans);
    }
    void processkWordLine(vector<string>&currLine,vector<string>&ans,int &currLen,int &maxWidth){
        string currans="";
        int evenSpaces=(maxWidth-currLen)/(currLine.size()-1);
        int remSpaces=(maxWidth-currLen)%(currLine.size()-1);
        for(int i=0;i<currLine.size()-1;++i){
            currans+=currLine[i];
            for(int space=0;space<evenSpaces;++space){
                currans+=" ";
            }
            if(remSpaces){
                currans+=" ";
                --remSpaces;
            }
        }
        currans+=currLine[currLine.size()-1];
        ans.push_back(currans);
    }
    void processLastLine(vector<string>&currLine,vector<string>&ans,int &currLen,int &maxWidth){
        string currans="";
        int spaces=(maxWidth-currLen);
        for(int i=0;i<currLine.size();++i){
            if(i==0){
                currans+=currLine[i];
            }else{
                currans=currans+" "+currLine[i];
                --spaces;
            }
        }
        while(spaces--) currans+=" ";
        ans.push_back(currans);
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n=words.size(),currLen=words[0].size();
        vector<string>ans,currLine;
        currLine.push_back(words[0]);
        for(int i=1;i<n;++i){
            if(currLen+words[i].size()+currLine.size()<=maxWidth){
                currLine.push_back(words[i]);
                currLen+=words[i].size();
            }else{
                if(currLine.size()==1){
                    processOneWordLine(currLine,ans,currLen,maxWidth);
                }else{
                    processkWordLine(currLine,ans,currLen,maxWidth);
                }
                currLine={words[i]};
                currLen=words[i].size();
            }
        }
        processLastLine(currLine,ans,currLen,maxWidth);
        return ans;
    }
};