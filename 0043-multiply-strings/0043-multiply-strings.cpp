class Solution {
public:
    string multiply(string num1, string num2) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);

        if (num1 == "0" || num2 == "0") return "0";
        
        vector<int> res(num1.size()+num2.size(), 0);
        
        for (int i = num1.size()-1; i >= 0; --i) {
            for (int j = num2.size()-1; j >= 0; --j) {
                res[i + j + 1] += (num1[i]-'0') * (num2[j]-'0');
                res[i + j] += res[i + j + 1] / 10;
                res[i + j + 1] %= 10;
            }
        }
        
        int i = 0;
        string ans = "";
        while (res[i] == 0) ++i;
        while (i < res.size()) ans += to_string(res[i++]);
        
        return ans;
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