class Solution {
public:

    long long getCount(long long x, vector<int>& coins)
    {
        int n = coins.size();
        long long ans = 0;

        for(int mask = 1; mask < (1 << n); mask++)
        {
            long long lcm = 1;
            int cnt = 0;

            for(int i = 0; i < n; i++)
            {
                if(mask & (1 << i))
                {
                    cnt++;

                    long long g = gcd(lcm, (long long)coins[i]);

                    if(lcm / g > x / coins[i])
                    {
                        lcm = x + 1;
                        break;
                    }

                    lcm = lcm / g * coins[i];
                }
            }

            if(lcm > x)
                continue;

            if(cnt % 2 == 1)
                ans += x / lcm;
            else
                ans -= x / lcm;
        }

        return ans;
    }

    long long findKthSmallest(vector<int>& coins, int k)
    {
        long long left = 1;

        long long mn = *min_element(coins.begin(), coins.end());
        long long right = mn * k;

        while(left < right)
        {
            long long mid = left + (right - left) / 2;

            if(getCount(mid, coins) >= k)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};