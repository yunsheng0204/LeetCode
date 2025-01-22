class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int row_len = isWater.size();
        int col_len = isWater[0].size();

        vector<vector<int>> ans(row_len, vector<int> (col_len, -1));
        queue<vector<int>> q;

        int temp_number = 0;
        int temp_row = 0;
        int temp_col = 0;

        for(int i = 0; i<row_len; i++)
        {
            for(int j = 0; j<col_len; j++)
            {
                if(isWater[i][j] == 1)
                {
                    ans[i][j] = 0;
                    q.push(vector<int>{0, i, j});
                }
            }
        }

        while(q.size() != 0)
        {
            temp_number = q.front()[0] + 1;
            temp_row = q.front()[1];
            temp_col = q.front()[2];

            q.pop();

            if(temp_row-1 != -1)
            {
                if(ans[ temp_row-1 ][ temp_col ] == -1)             // 上
                {
                    ans[ temp_row-1 ][ temp_col ] = temp_number;
                    q.push(vector<int>{temp_number, temp_row-1, temp_col});
                }
            }
            if(temp_row+1 != row_len)
            {
                if(ans[ temp_row+1 ][ temp_col ] == -1)             // 下
                {
                    ans[ temp_row+1 ][ temp_col ] = temp_number;

                    q.push(vector<int>{temp_number, temp_row+1, temp_col});
                }
            }
            if(temp_col-1 != -1)
            {
                if(ans[ temp_row ][ temp_col-1 ] == -1)             // 左
                {
                    ans[ temp_row ][ temp_col-1 ] = temp_number;

                    q.push(vector<int>{temp_number, temp_row, temp_col-1});
                }
            }
            if(temp_col+1 != col_len)
            {
                if(ans[ temp_row ][ temp_col+1 ] == -1)             // 右
                {
                    ans[ temp_row ][ temp_col+1 ] = temp_number;

                    q.push(vector<int>{temp_number, temp_row, temp_col+1});
                }
            }
        }
        return ans;
    }
};