class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len, 1);
        vector<int> prev(len, -1);
        sort(nums.begin(), nums.end());
        int maxi = 0;
        int max_index = len - 1;

        for(int i = 1; i<len; i++)
        {
            for(int j = i-1; j>=0; j--)
            {
                if(nums[i] % nums[j] == 0)
                {
                    if(dp[j] + 1 > dp[i])
                    {
                        prev[i] = j;
                        dp[i] = dp[j] + 1;
                    }
                }
            }
        }

        maxi = dp[len - 1];
        max_index = len - 1;
        for(int i = len - 2; i>=0; i--)
        {
            if(maxi < dp[i])
            {
                maxi = dp[i];
                max_index = i;
            }
        }

        len = dp[max_index];
        vector<int> ans(dp[max_index], 0);
        ans[len - 1] = nums[max_index];
        for(int i = len - 2; i>=0; i--)
        {
            ans[i] = nums[prev[max_index]];
            max_index = prev[max_index];
        }

        return ans;
    }
};