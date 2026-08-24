class Solution {
public:
    int dp(vector<int>& stones, vector<int>& d, vector<int>& prefix, vector<bool>& check, int len, int index)
    {
        if(index == len - 1)
        {
            check[index] = true;
            d[index] = prefix[index];
        }
        else
        {
            if(check[index] == false)
            {
                d[index] = max(dp(stones, d, prefix, check, len, index + 1), prefix[index] - dp(stones, d, prefix, check, len, index + 1));
                check[index] = true;
            }
        }
        return d[index];
    }
    int stoneGameVIII(vector<int>& stones) {
        int len = stones.size();
        vector<int> prefix(len, 0);
        vector<int> d(len, 0);
        vector<bool> check(len, false);

        prefix[0] = stones[0];
        for(int i = 1; i<len; i++)
        {
            prefix[i] = prefix[i-1] + stones[i];
        }

        
        int ans = dp(stones, d, prefix, check, len, 1);
        
        return ans;
    }
};