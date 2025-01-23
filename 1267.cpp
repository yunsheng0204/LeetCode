class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int row_len = grid.size();
        int col_len = grid[0].size();

        int temp = 0;
        int c = 0;

        vector<int> count_row;
        vector<int> count_col;

        int ans = 0;


        int mini = min(row_len, col_len);
        bool mini_row_col = 0;
        if(row_len < col_len)
        {
            mini_row_col = 0;
        }
        else
        {
            mini_row_col = 1;
        }


        for(int i = 0; i<row_len; i++)
        {
            for(int j =0; j<col_len; j++)
            {
                temp += grid[i][j];
            }
            count_row.push_back(temp);
            ans += temp;
            temp = 0;
        }

        for(int i = 0; i<col_len; i++)
        {
            for(int j =0; j<row_len; j++)
            {
                temp += grid[j][i];
            }
            count_col.push_back(temp);
            ans += temp;
            temp = 0;
        }

        for(int i = 0; i<mini; i++)
        {
            for(int j = 0; j<mini; j++)
            {
                if(count_row[i] == 1 && count_col[j] == 1 && grid[i][j] == 1)
                {
                    ans -= 2;
                }
            }
        }
        if(mini_row_col == 0)
        {
            
            for(c = mini; c<col_len; c++)
            {
                for(int i = 0; i<row_len; i++)
                {
                    if(count_row[i] == 1 && count_col[c] == 1 && grid[i][c] == 1)
                    {
                        ans-=2;
                    }
                }
            }
        }
        else
        {
            for(c = mini; c<row_len; c++)
            {
                for(int i = 0; i<col_len; i++)
                {
                    if(count_row[c] == 1 && count_col[i] == 1 && grid[c][i] == 1)
                    {
                        ans-=2;
                    }
                }
            }
        }
        return ans/2;
    }
};