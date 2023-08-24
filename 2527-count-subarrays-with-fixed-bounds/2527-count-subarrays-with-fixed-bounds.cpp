/*
// [1,2,3,4,7,5,2,5,6,7,8,1,2,3,4,5,7,2,3,4,5,7,8,1,2,3,4,5] mink=2 maxk=7
// [2,3,4,7,5,2,5,6,7] [2,3,4,5,7,2,3,4,5,7] [2,3,4,5]
// [0,1,2,3,4,5,6,7,8]
// [0,5,5,5,5,5,-1,-1,-1]
// [3,3,3,3,8,8,8,8,8]
// length-[max(minkindex,maxkindex)-pastIncorrectOcc];
// 9-3 + 9-5 + 9-5 + 9-5 +9-8 + 9-8
// 20
class Solution{
  public:
  long long countSubarrays(vector<int>&nums,int minK, int maxK){
    long long ans=0;
    int n=nums.size(),lastmin=-1,lastmax=-1;
    vector<int>minkIndex(n),maxkIndex(n),out;
    for(int i=n-1;i>=0;--i){
      if(nums[i]>maxK or nums[i]<minK){
        out.push_back(i);
        minkIndex[i]=-1;
        maxkIndex[i]=-1;
        lastmin=-1,lastmax=-1;
      }
      if(nums[i]==minK) lastmin=i;
      if(nums[i]==maxK) lastmax=i;
      minkIndex[i]=lastmin;
      maxkIndex[i]=lastmax;
    }
    int last=0,top;
    for(int i=out.size()-1;i>=0;--i){
      if(i==out.size()-1){ 
        if(out[i]-last==0) continue;
        top=out[i];
        for(int j=last;j<top;++j){
          if(minkIndex[j]==-1 or maxkIndex[j]==-1 or minkIndex[j]>top or maxkIndex[j]>top) continue;
          ans+=(top-max(minkIndex[j],maxkIndex[j]));
        }
      }else{
        last=out[i+1];
        top=out[i];
        int len=top-last-1;
        if(len==0) continue;
        for(int j=last+1;j<top;++j){
          if(minkIndex[j]==-1 or maxkIndex[j]==-1 or minkIndex[j]>top or maxkIndex[j]>top) continue;
          ans+=(len-(max(minkIndex[j],maxkIndex[j])-last-1));
        }
      }
    }
    if(!out.empty()) last=out[0];
    int len=n-(last==0?0:(last+1));
    for(int j=(last==0?last:(last+1));j<n;++j){
      if(minkIndex[j]==-1 or maxkIndex[j]==-1) continue;
      ans+=(len-(max(minkIndex[j],maxkIndex[j])-(last==0?0:(last+1))));
    }
    return ans;
  }
};


// n=9,mink=1,maxk=1
// 5,6,7,8
// 2,1,1,1
//-1,6,7,8
// last=5
// len=9-(5+1)=3
// j=6
// ans+=(3-(6-5));

//[4,3] n=2, mink=3, maxk=3
//[0,1]
//[1,1]
//[1,1]
*/



class Solution{
  public:
  long long countSubarrays(vector<int>&nums,int minK, int maxK){
    long long ans=0;
    int cultInd=-1,maxkInd=-1,minkInd=-1,n=nums.size();
    for(int i=0;i<n;++i){
      if(nums[i]>maxK or nums[i]<minK) cultInd=i;
      if(nums[i]==maxK) maxkInd=i;
      if(nums[i]==minK) minkInd=i;
      ans+=((min(minkInd,maxkInd)-cultInd)>0?(min(minkInd,maxkInd)-cultInd):0);
    }
    return ans;
  }
};