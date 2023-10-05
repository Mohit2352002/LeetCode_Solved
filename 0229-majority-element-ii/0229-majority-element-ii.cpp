class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int el1=-1,el2=-1,count1=0,count2=0;
        for(int el:nums){
            if(count1==0 and el!=el2){
                el1=el; 
                ++count1;
            }
            else if(count2==0 and el!=el1){
                ++count2;
                el2=el;
            }
            else if(el1==el) ++count1;
            else if(el2==el) ++count2;
            else{
                --count1;
                --count2;
            }
        }
        count1=0;
        count2=0;
        for(int el:nums){
            if(el==el1) ++count1;
            else if(el==el2) ++count2;
        }
        vector<int>ans; 
        if(count1>nums.size()/3) ans.push_back(el1);
        if(count2>nums.size()/3) ans.push_back(el2); 
        return ans;
    }
};