class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int row_len = mat.size();
        int col_len = mat[0].size();

        vector<int> hash_table_row(row_len*col_len, -1);
        vector<int> hash_table_col(row_len*col_len, -1);

        for(int i = 0; i<row_len; i++)
        {
            for(int j = 0; j<col_len; j++)
            {
                hash_table_row[ mat[i][j]-1 ] = i;
                hash_table_col[ mat[i][j]-1 ] = j;
            }
        }

        int len = arr.size();

        vector<int> check_row(row_len, 0);
        vector<int> check_col(col_len, 0);

        for(int i = 0; i<len; i++)
        {
            if( ++check_row[ hash_table_row[ arr[i]-1 ] ] == col_len)
            {
                return i;
            }
            if( ++check_col[ hash_table_col[ arr[i]-1 ] ] == row_len)
            {
                return i;
            }
        }

        return -1;
    }
};