class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        if(nums.size()<3) return -1;
        int min_i=-1,max_i=-1,max_el=INT_MIN,min_el=INT_MAX;
        for(int i=0;i<nums.size();++i){
            if(max_i!=-1 and min_el!=max_el){
                if(nums[i]>max_el) return nums[max_i];
                if(nums[i]<min_el) return nums[min_i];
                if(nums[i]!=min_el and nums[i]!=max_el) return nums[i];
            }
            if(max_i==-1 or nums[i]>max_el){
                max_i=i;
                max_el=nums[i];
            }
            if(min_i==-1 or nums[i]<min_el){
                min_i=i;
                min_el=nums[i];
            }
        }
        return -1;
    }
};