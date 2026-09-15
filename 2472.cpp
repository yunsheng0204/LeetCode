class Solution {
public:
    bool isPalindrome(string& s, int left, int right)
    {
        while(left < right)
        {
            if(s[left] != s[right])
                return false;

            left++;
            right--;
        }

        return true;
    }

    int maxPalindromes(string s, int k)
    {
        int n = s.size();

        vector<int> dp(n + 1, 0);

        for(int i = 1; i <= n; i++)
        {
            dp[i] = dp[i - 1];

            if(i >= k && isPalindrome(s, i - k, i - 1))
            {
                dp[i] = max(dp[i], dp[i - k] + 1);
            }

            if(i >= k + 1 && isPalindrome(s, i - k - 1, i - 1))
            {
                dp[i] = max(dp[i], dp[i - k - 1] + 1);
            }
        }

        return dp[n];
    }
};