
class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int len = nums.size();

        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for(int i = 0; i < len; i++)
        {
            vector<long long> next(k, 0);

            int x = nums[i] % k;

            next[x]++;

            for(int j = 0; j < k; j++)
            {
                int r = (j * x) % k;

                next[r] += dp[j];
            }

            dp = next;

            for(int j = 0; j < k; j++)
            {
                ans[j] += dp[j];
            }
        }

        return ans;
    }
};