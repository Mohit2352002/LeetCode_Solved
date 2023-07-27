static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
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
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie tr;
        int n=nums.size();
        for(int i=0;i<n;++i){
            tr.insert(nums[i]);
        }
        int maxi=0;
        for(int i=0;i<n;++i){
            maxi=max(maxi,tr.getMax(nums[i]));
        }
        return maxi;
    }
};