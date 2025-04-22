class Solution {
    public:
        const int MOD = 1e9 + 7;
        vector<long long> fact, invFact;
    
        long long power(long long a, long long b)
        {
            long long res = 1;
            while (b)
            {
                if (b % 2) res = res * a % MOD;
                a = a * a % MOD;
                b >>= 1;
            }
            return res;
        }
    
        void initFactorials(int n)
        {
            fact.resize(n + 1);
            invFact.resize(n + 1);
            fact[0] = invFact[0] = 1;
            for (int i = 1; i <= n; i++)
            {
                fact[i] = fact[i - 1] * i % MOD;
            }
            invFact[n] = power(fact[n], MOD - 2);
            for (int i = n - 1; i >= 1; i--)
            {
                invFact[i] = invFact[i + 1] * (i + 1) % MOD;
            }
        }
    
        long long comb(int n, int k)
        {
            if (k > n || k < 0) return 0;
            return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
        }
    
        int idealArrays(int n, int maxValue)
        {
            initFactorials(n);
            unordered_map<int, vector<int>> dp;
            vector<vector<int>> factors(maxValue + 1);
            for (int i = 1; i <= maxValue; i++)
            {
                for (int j = 2 * i; j <= maxValue; j += i)
                {
                    factors[i].push_back(j);
                }
            }
    
            for (int x = 1; x <= maxValue; x++)
            {
                dp[x] = vector<int>(15, 0);
                dp[x][1] = 1;
            }
    
            for (int len = 2; len <= 14; len++)
            {
                for (int x = 1; x <= maxValue; x++)
                {
                    for (int nxt : factors[x])
                    {
                        if (dp.find(nxt) == dp.end())
                        {
                            dp[nxt] = vector<int>(15, 0);
                        }
                        dp[nxt][len] = (dp[nxt][len] + dp[x][len - 1]) % MOD;
                    }
                }
            }
    
            long long ans = 0;
            for (auto& [val, counts] : dp)
            {
                for (int len = 1; len <= 14; len++)
                {
                    if (counts[len] == 0) continue;
                    ans = (ans + counts[len] * comb(n - 1, len - 1) % MOD) % MOD;
                }
            }
    
            return (int)ans;
        }
    };
    