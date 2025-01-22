class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int len_row = matrix.size();
        int len_col = matrix[0].size();

        for(int i = 0; i<len_row; i++)
        {
            for(int j = 0; j<len_col; j++)
            {
                if(target == matrix[i][j])
                {
                    return true;
                }
            }
        }
        return false;
    }
};