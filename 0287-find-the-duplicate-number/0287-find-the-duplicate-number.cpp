class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);

        // Find the intersection point of the two runners.
        int tortoise = nums[0];
        int hare = nums[0];

        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (tortoise != hare);

        // Find the "entrance" to the cycle.
        tortoise = nums[0];
        while (tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }

        return hare;
    }
};









/*
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        while (nums[0] != nums[nums[0]])
            swap(nums[0], nums[nums[0]]);
        return nums[0];
    }
};*/









/*
//negative manipulation
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int curr,n=nums.size(),i=0;
        while(i<n){
            curr=abs(nums[i]);
            if(nums[curr]<0) return curr;
            else nums[curr]*=-1;
            ++i;
        }
        return -1;
    }
};*/









/*
//binary search TC=O(NlogN)
class Solution {
    int lessequalcounter(vector<int>& nums, int mid){
        int count=0;
        for(auto &el:nums) if(el<=mid) ++count;
        return count;
    }
public:
    int findDuplicate(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int high=nums.size()-1,low=0,mid=0;
        while(low<high){
            mid=low+(high-low)/2;
            if(lessequalcounter(nums,mid)>mid) high=mid;
            else low=mid+1;
        }
        return low;
    }
};
*/