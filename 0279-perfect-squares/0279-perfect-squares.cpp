class Solution {
public:
    int numSquares(int n) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        if(n<4) return n;
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0,dp[1]=1,dp[2]=2,dp[3]=3;
        for(int i=4;i<=n;++i){
            for(int j=1;j*j<=i;++j){
                dp[i]=min(dp[i],dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};










/*
class Solution { 
public:
    int is_square(int n)
    {  
        int sqrt_n = (int)(sqrt(n));  
        return (sqrt_n*sqrt_n == n);  
    }
    int numSquares(int n) 
    {  
        // If n is a perfect square, return 1.
        if(is_square(n)) 
        {
            return 1;  
        }
        
        // The result is 4 if and only if n can be written in the 
        // form of 4^k*(8*m + 7). Please refer to 
        // Legendre's three-square theorem.
        while ((n & 3) == 0) // n%4 == 0  
        {
            n >>= 2;  
        }
        if ((n & 7) == 7) // n%8 == 7
        {
            return 4;
        }
        
        // Check whether 2 is the result.
        int sqrt_n = (int)(sqrt(n)); 
        for(int i = 1; i <= sqrt_n; i++)
        {  
            if (is_square(n - i*i)) 
            {
                return 2;  
            }
        }  
        
        return 3;  
    }  
};*/





/*
class Solution {
public:
	int numSquares(int n) {
		//using Lagrange's four-square theorem, also known as Bachet's conjecture, states that every natural 
		//number can be represented as the sum of four integer squares. 

		vector<int> sqr;
		int x=1;
		while(x*x<=n){ //saving all squares till n
			sqr.push_back(x*x);
			x++;
		}
		int size= sqr.size();

		for(int i=0; i<size; i++){ //for one
			if(sqr[i]==n)
				return 1;
		}

		for(int i=0; i<size; i++){
			for(int j=i; j<size; j++){ //for two
				if(sqr[i]+sqr[j]==n)
					return 2;
			}
		}

		for(int i=0; i<size; i++){ //for three
			for(int j=i; j<size; j++){
				for(int k=j; k<size; k++){
					if(sqr[i]+sqr[j]+sqr[k]==n)
						return 3;
				}
			}
		}

		return 4; //if not 1,2,3 then definitely 4
	}
};*/