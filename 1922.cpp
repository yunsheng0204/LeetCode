class Solution {
    public:
        int countGoodNumbers(long long n) {
            long long ans = 1;
            long long odd = n/2;
            long long evan = (n + 1)/2;
            long long mod = pow(10,9) + 7;
            long long base;
    
            base = 4;
    
            while (odd > 0) 
            {
                if (odd % 2 == 1) 
                {
                    ans = (ans * base) % mod;
                }
                base = (base * base) % mod;
                odd /= 2;
            }
    
            base = 5;
    
            while (evan > 0) 
            {
                if (evan % 2 == 1) 
                {
                    ans = (ans * base) % mod;
                }
                base = (base * base) % mod;
                evan /= 2;
            }
    
            return (int)ans;
        }
    };