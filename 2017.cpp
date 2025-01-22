class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long min1 = 0;
        long long temp = 0;
        
        long long len = grid[0].size();

        vector<vector<long long>> prefix_sum(2, vector<long long>(len, 0));

        prefix_sum[0][len-1] = 0;
        prefix_sum[1][0] = 0;

        for(long long i = 1; i<len; i++)
        {
            prefix_sum[0][len-i-1] = grid[0][len-i] + prefix_sum[0][len-i];
            prefix_sum[1][i] = grid[1][i-1] + prefix_sum[1][i-1];
        }

        min1 = max(prefix_sum[0][0], prefix_sum[1][0]);
        for(long long i = 1; i<len; i++)
        {
            temp = max(prefix_sum[0][i], prefix_sum[1][i]);
            if(min1>temp)
            {
                min1 = temp;
            }
        }
        return min1;
    }
};