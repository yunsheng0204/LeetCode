class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int row_len = grid.size();
        int col_len = grid[0].size();

        int max = 0;

        vector<vector<int>> find = grid;
        vector<vector<bool>> check(row_len, vector<bool>(col_len, false));

        for(int i = 0; i<row_len; i++)
        {
            for(int j = 0; j<col_len; j++)
            {
                if(check[i][j] != true)
                {
                    // cout<<i<<" "<<j<<endl;
                    explore(find, grid, check, i, j, row_len, col_len, max, 0, 0);
                }
            }
        }
        for(int i = 0; i<row_len; i++)
        {
            for(int j = 0; j<col_len; j++)
            {
                cout<<find[i][j]<<" ";
            }
            cout<<endl;
        }
        return max;
    }
    void explore(vector<vector<int>>& find, vector<vector<int>>& grid, vector<vector<bool>>& check, int row, int col, int row_len, int col_len, int &max, int parent, int direction)
    {
        if(check[row][col] == true)
        {
            return;
        }
        else
        {
            if(find[row][col] == 0)
            {
                check[row][col] = true;
                return;
            }
            else
            {
                check[row][col] = true;
                find[row][col] = parent + find[row][col];
                switch(direction)
                {
                    case 1:
                        if(find[row][col] > find[row+1][col])
                        {
                            find[row+1][col] = find[row][col];
                        }
                        else
                        {
                            find[row][col] = find[row+1][col];
                        }
                        break;
                    case 2:
                        if(find[row][col] > find[row-1][col])
                        {
                            find[row-1][col] = find[row][col];
                        }
                        else
                        {
                            find[row][col] = find[row-1][col];
                        }
                        break;
                    case 3:
                        if(find[row][col] > find[row][col+1])
                        {
                            find[row][col+1] = find[row][col];
                        }
                        else
                        {
                            find[row][col] = find[row][col+1];
                        }
                        break;
                    case 4:
                        if(find[row][col] > find[row][col-1])
                        {
                            find[row][col-1] = find[row][col];
                        }
                        else
                        {
                            find[row][col] = find[row][col-1];
                        }
                        break;
                }
                if(max < find[row][col])
                {
                    max = find[row][col];
                }
                bool check2[5] = {false};
                if(row-1 != -1)
                {
                    check2[1] = true;
                    explore(find, grid, check, row-1, col, row_len, col_len, max, find[row][col], 1);
                }
                if(row+1 != row_len)
                {
                    check2[2] = true;
                    explore(find, grid, check, row+1, col, row_len, col_len, max, find[row][col], 2);
                }
                if(col-1 != -1)
                {
                    check2[3] = true;
                    explore(find, grid, check, row, col-1, row_len, col_len, max, find[row][col], 3);
                }
                if(col+1 != col_len)
                {
                    check2[4] = true;
                    explore(find, grid, check, row, col+1, row_len, col_len, max, find[row][col], 4);
                }

                if(check2[1] == true)
                {
                    find[row-1][col] = find[row][col];
                }
                if(check2[2] == true)
                {
                    find[row+1][col] = find[row][col];
                }
                if(check2[3] == true)
                {
                    find[row][col-1] = find[row][col];
                }
                if(check2[4] == true)
                {
                    find[row][col+1] = find[row][col];
                }
            }
        }
    }
};