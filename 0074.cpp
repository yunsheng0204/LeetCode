class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int len = matrix.size();
        int i = 0;
        int row = 0;

        for(i = 0; i<len; i++)
        {
            if(matrix[i][0]>target)
            {
                row = i - 1;
                break;
            }
        }
        if(i == len || i == 0)
        {
            row = len - 1;
        }
    
        cout<<row;

        for(int c = 0; c<matrix[row].size(); c++)
        {
            if(matrix[row][c] == target)
            {
                return 1;
            }
        }

        return 0;
    }
};