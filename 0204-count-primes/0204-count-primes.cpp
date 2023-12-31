class Solution {
    int SieveOfEratosthenes(int n){
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    int count=0;
    int ans=n/2;
  
    for (int p = 3; p * p < n; p+=2) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int i = p * p; i < n; i += 2*p)
                if(prime[i]){
                    prime[i] = false;
                    --ans;
                }
        }
    }
  
    // Count all prime numbers
    // for (int p = 2; p < n; p++)
    //     if (prime[p])
    //         count++;
    
    // return count;
    return ans;
}
public:
    int countPrimes(int n) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        if(n<3) return 0;
        return SieveOfEratosthenes(n);
    }
};