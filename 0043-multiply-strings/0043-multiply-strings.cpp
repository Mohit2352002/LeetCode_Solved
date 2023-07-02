


class Solution {
public:
    string multiply(string nums1, string nums2) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);

        if (nums1 == "0" || nums2 == "0") return "0";

        int n=nums1.size(),m=nums2.size();
        vector<int>ans(n+m,0);

        for(int i=n-1;i>=0;--i){
            for(int j=m-1;j>=0;--j){
                ans[i+j+1]+=(nums1[i]-'0')*(nums2[j]-'0');
                ans[i+j]+=ans[i+j+1]/10;
                ans[i+j+1]%=10;
            }
        }

        int i=0;
        while(ans[i]==0) ++i;
        string res="";
        while(i<n+m){
            res+=to_string(ans[i++]);
        }

        return res;
    }
};







/*
class Solution {
public:
    string multiply(string a, string b){
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        if (a=="0" || b=="0")  return "0";
        int m = a.size() - 1, n = b.size() - 1, carry = 0;
        string product;
        for (int i=0; i<=m+n || carry; ++i) 
        {
            for (int j = max(0, i-n); j <= min(i, m); ++j)
                carry += (a[m-j] - '0') * (b[n-i+j] - '0');
            product += carry % 10 + '0';
            carry /= 10;
        }
        reverse(begin(product), end(product));
        return product;
    }
};*/