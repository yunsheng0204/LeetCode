class Solution {
    public:
        long long countGoodIntegers(int n, int k) {
            if (n == 1) 
            {
                long long ans = 0;
                for (int d = 1; d <= 9; d++) 
                {
                    if (d % k == 0) 
                    {
                        ans++;
                    }
                }
                return ans;
            }
    
            int half_len = n / 2;
            long long start = 1;
            long long end = 1;
            string half;
            string rev_half;
            string full;
    
            long long len;
            long long ans = 0;
    
            vector<long long> q;
    
            if (half_len == 0) 
            {
                start = 0;
            } 
            else 
            {
                for (int i = 1; i < half_len; i++) 
                {
                    start *= 10;
                }
            }
    
            for (int i = 0; i < half_len; i++) 
            {
                end *= 10;
            }
    
            for (int i = start; i < end; i++) 
            {
                half = to_string(i);
                rev_half = half;
                reverse(rev_half.begin(), rev_half.end());
    
                if (n % 2 == 0) 
                {
                    full = half + rev_half;
                    q.push_back(stoll(full));
                } 
                else 
                {
                    for (int d = 0; d <= 9; d++) 
                    {
                        full = half + char(d + '0') + rev_half;
                        q.push_back(stoll(full));
                    }
                }
            }
            
            len = q.size();
    
            unordered_set<string> seen;
    
            for(long long i = 0; i < len; i++) 
            {
                if (q[i] % k != 0) continue;
    
                string digits = to_string(q[i]);
    
                sort(digits.begin(), digits.end());
                if (seen.count(digits)) continue;
    
                seen.insert(digits);
                ans += count_valid_permutations(to_string(q[i]));
            }
    
            return ans;
        }
    
        long long factorial(long long x) {
            long long res = 1;
            for (long long i = 2; i <= x; i++) 
            {
                res *= i;
            }
            return res;
        }
    
            long long count_valid_permutations(string number) {
            map<char, long long> freq;
            long long n = number.size();
    
            for (long long i = 0; i < n; i++) {
                freq[number[i]]++;
            }
    
            long long total = 0;
    
            for (map<char, long long>::iterator it = freq.begin(); it != freq.end(); it++) 
            {
                char first_digit = it->first;
                if (first_digit == '0' || it->second == 0) continue;
    
                freq[first_digit]--;
    
                long long count = factorial(n - 1);
                for (map<char, long long>::iterator jt = freq.begin(); jt != freq.end(); jt++) 
                {
                    count /= factorial(jt->second);
                }
    
                total += count;
    
                freq[first_digit]++;
            }
    
            return total;
        }
    
    };