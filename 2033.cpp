class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            int len_row = grid.size();
            int len_col = grid[0].size();
            int len = len_row * len_col;
            int remainder = grid[0][0] % x;
            int middle;
            int ans = 0;
            vector<int> queue;
    
            for(int i = 0; i<len_row; i++)
            {
                for(int j = 0; j<len_col; j++)
                {
                    if(grid[i][j] % x != remainder)
                    {
                        return -1;
                    }
                    else
                    {
                        queue.push_back(grid[i][j]);
                    }
                }
            }
            sort(queue.begin(), queue.end());
            middle = queue[len/2];
    
            for(int i = 0; i<len; i++)
            {
                ans += abs(queue[i] - middle) / x;
            }
            return ans;
        }
    };