class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row_len = grid.size();
        int col_len = grid[0].size();

        for(int i = row_len-2; i>=0; i--)
        {
            grid[i][col_len-1] = grid[i][col_len-1] + grid[i+1][col_len-1];
        }
        for(int i = col_len-2; i>=0; i--)
        {
            grid[row_len-1][i] = grid[row_len-1][i] + grid[row_len-1][i+1];
        }
        for(int i = row_len-2; i>=0; i--)
        {
            for(int j = col_len-2; j>=0; j--)
            {
                grid[i][j] = grid[i][j] + min(grid[i+1][j],grid[i][j+1]);
            }
        }
        return grid[0][0];
    }
};