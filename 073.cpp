class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int max = 0;
        int temp = 0;

        if(row>col)
        {
            max = row;
        }
        else
        {
            max = col;
        }

        vector<int> check_row;
        vector<int> check_col;


        for(int i = 0; i<row; i++)
        {
            for(int j = 0; j<col; j++)
            {
                if(matrix[i][j] == 0)
                {
                    check_row.push_back(i);
                    check_col.push_back(j);
                }
            }
        }
        while(check_row.size()!=0)
        {
            temp = check_row[0];
            check_row.erase(check_row.begin());

            for(int i = 0; i<col; i++)
            {
                matrix[temp][i] = 0;
            }
        }
        while(check_col.size()!=0)
        {
            temp = check_col[0];
            check_col.erase(check_col.begin());

            for(int i = 0; i<row; i++)
            {
                matrix[i][temp] = 0;
            }
        }
    }
};