class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int basket1=-1,basket2=-1, fruit_idx1=-1,fruit_idx2=-1,n=fruits.size(),i=0,j=0,ans=1;
        while(j<n){
            if(fruits[j]==basket1 || fruits[j]==basket2){
                if(fruits[j]==basket1) fruit_idx1=j;
                else fruit_idx2=j;
                ++j;
            }else if(basket1==-1){
                fruit_idx1=j;
                basket1=fruits[j++];
            }else if(basket2==-1){
                fruit_idx2=j;
                basket2=fruits[j++];
            }else{
                if(fruit_idx1>fruit_idx2){
                    i=fruit_idx2+1;
                    basket2=fruits[j];
                    fruit_idx2=j;
                }else{
                    i=fruit_idx1+1;
                    basket1=fruits[j];
                    fruit_idx1=j;
                }
                ++j;
            }
            ans=max(ans,j-i);
        }
        return ans;
    }
};