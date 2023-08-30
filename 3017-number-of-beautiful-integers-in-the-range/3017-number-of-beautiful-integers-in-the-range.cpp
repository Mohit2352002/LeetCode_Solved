class Solution {
public:
    int check(int low) {
        int even = 0;
        int odd = 0;

        while (low > 0) {
            if (low % 2 == 0) {
                even++;
            } else {
                odd++;
            }

            low /= 10;
        }

        if (even == odd) {
            return 1;
        } else {
            return 0;
        }
    }

    int numberOfBeautifulIntegers(int low, int high, int k) {
        low = ((low - 1) / k + 1) * k;
        int count = 0;
        while (low <= high) {
            count += check(low);
            low += k;

            if (low >= 100000000) {
                return count;
            }
        }

        return count;
    }
};