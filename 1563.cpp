class Solution {
public:

    int check(int left, int right, vector<int>& stoneValue, vector<int>& prefix, vector<vector<int>>& dp)
    {
        if(left == right)
        {
            return 0;
        }

        if(dp[left][right] != -1)
        {
            return dp[left][right];
        }

        int an = 0;

        for(int i = left; i < right; i++)
        {
            int L = prefix[i + 1] - prefix[left];
            int R = prefix[right + 1] - prefix[i + 1];

            if(L < R)
            {
                an = max(
                    an,
                    L + check(left, i, stoneValue, prefix, dp)
                );
            }
            else if(L > R)
            {
                an = max(
                    an,
                    R + check(i + 1, right, stoneValue, prefix, dp)
                );
            }
            else
            {
                int left_score =
                    L + check(left, i, stoneValue, prefix, dp);

                int right_score =
                    R + check(i + 1, right, stoneValue, prefix, dp);

                an = max(
                    an,
                    max(left_score, right_score)
                );
            }
        }

        dp[left][right] = an;

        return an;
    }


    int stoneGameV(vector<int>& stoneValue)
    {
        int len = stoneValue.size();

        vector<int> prefix(len + 1, 0);

        for(int i = 1; i <= len; i++)
        {
            prefix[i] =
                prefix[i - 1] + stoneValue[i - 1];
        }

        vector<vector<int>> dp(
            len,
            vector<int>(len, -1)
        );

        return check(
            0,
            len - 1,
            stoneValue,
            prefix,
            dp
        );
    }
};