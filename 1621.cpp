class Solution {
public:
    int numberOfSets(int n, int k)
    {
        int mod = 1000000007;

        vector<vector<long long>> dp(n, vector<long long>(k + 1, 0));
        vector<vector<long long>> sum(n, vector<long long>(k + 1, 0));

        for(int i = 0; i < n; i++)
        {
            dp[i][0] = 1;
            sum[i][0] = i + 1;
        }

        for(int j = 1; j <= k; j++)
        {
            for(int i = 1; i < n; i++)
            {
                dp[i][j] = (dp[i - 1][j] + sum[i - 1][j - 1]) % mod;
                sum[i][j] = (sum[i - 1][j] + dp[i][j]) % mod;
            }
        }

        return dp[n - 1][k];
    }
};