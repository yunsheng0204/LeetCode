class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int MOD = 1e9 + 7;
        int len = s.size();
        int times = t / 26;
        int r = t % 26;
        vector<long long> count(26,0);
        vector<long long> next_count(26,0);
        long long ans = 0;


        for(int i = 0; i<len; i++)
        {
            count[s[i] - 'a']++;
        }

        for(int i = 0; i<times; i++)
        {
            for(int j = 1; j<25; j++)
            {
                next_count[j + 1] = (count[j + 1] + count[j]) % MOD;
            }
            next_count[0] = (count[0] + count[25]) % MOD;
            next_count[1] = (count[0] + count[1] + count[25]) % MOD;

            count = next_count;
        }

        for(int i = 0; i<26; i++)
        {
            ans += count[i];
            ans %= MOD;
        }

        for(int i = 0; i<r; i++)
        {
            ans += count[25 - i];
            ans %= MOD;
        }


        return (int)ans;
    }
};
