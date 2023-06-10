class Solution {
public:
   long long  int test(int a,int index,int n){
        long long int b=max(0,a-index);//leftElements
        long long int res=(a+b)*(a-b+1)/2;//leftSum
        b=max(0,(a-((n-1)-index)));//rigthElements
        res=res+(a+b)*(a-b+1)/2;//rightSum
        return res-a;//netSum as mid got added twice 
    }
    int maxValue(int n, int index, int maxSum) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        maxSum=maxSum-n;
        int l=0,r=maxSum;
        while(l<r){
            int m=(l+r+1)/2;
            if(test(m,index,n)>maxSum) r=m-1;
            else l=m;
        }
        return l+1;
    }
};






/*
#define ll long long int
class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int emptyR = n - index - 1;
        int emptyL = index;
        int h = maxSum, l = 1;
        ll res = 0;
        while(l <= h){
            int mid = (h-l)/2 + l;
            ll leftSum = 0, rightSum=0, el=mid-1;
            if(emptyR <= el) rightSum = (el*(el+1))/2 - ((el-emptyR)*(el-emptyR+1))/2;
            else rightSum = (el*(el+1))/2 + (emptyR - el);
            if(emptyL <= el) leftSum = (el*(el+1))/2 - ((el-emptyL)*(el-emptyL+1))/2;
            else leftSum = (el*(el+1))/2 + (emptyL - el);
            ll sum = leftSum + mid + rightSum;
            if(sum <= maxSum){
                l = mid+1;
                res = mid;
            }else h = mid-1;
        }
        return res;
    }
};*/