static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
struct Node{
    Node* link[2];
};
class Trie{
    private: Node* root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(int num){
        Node*node=root;
        for(int i=30;i>=0;--i){
            int bit=((num>>i)&1);
            if(node->link[bit]==NULL){
                node->link[bit]=new Node();
            }
            node=node->link[bit];
        }
    }
    int getMax(int num){
        Node*node=root;
        int maxNum=0;
        for(int i=30;i>=0;--i){
            int bit=((num>>i)&1);
            if(node->link[1^bit]!=NULL){
                maxNum|=(1<<i);
                node=node->link[1^bit];
            }else{
                node=node->link[bit];
            }
        }
        return maxNum;
    }
};
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int t=queries.size(),i=0,j=0,n=nums.size(),maxi;
        vector<vector<int>>qu(t,vector<int>(3));
        for(;i<t;++i){
            qu[i][0]=queries[i][0];
            qu[i][1]=queries[i][1];
            qu[i][2]=i;
        }
        sort(qu.begin(),qu.end(),[&](const vector<int>&a,const vector<int>&b){
            return a[1]<b[1];
        });
        vector<int>ans(t);
        sort(nums.begin(),nums.end(),[&](const int &a,const int&b){
            return a<b;
        });
        Trie tr;
        i=0;
        while(t--){
            //int maxi=-1;
            for(;j<n and nums[j]<=qu[i][1];++j){
                tr.insert(nums[j]);
            }
            // if(nums[0]>qu[i][1]){ 
            //     ans[qu[i++][2]]=maxi;
            //     continue;
            // }
            // maxi=max(maxi,tr.getMax(qu[i][0]));
            // ans[qu[i++][2]]=maxi;
            if(j==0) ans[qu[i++][2]]=-1;
            else{
                ans[qu[i][2]]=tr.getMax(qu[i][0]);
                ++i;
            }
            //if(j!=0) ans[qu[i][2]]=tr.getMax(qu[i++][0]);
            //else ans[qu[i++][2]]=-1;
        }
        return ans;
    }
};