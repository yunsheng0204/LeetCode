class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int temp = 0;
        int leng = matrix[0].size();
        int reverse = 0;

        vector<vector<int>> m(leng, vector<int>(leng)); 
        
        for(int i = 0; i<leng; i++)
        {
            reverse = (leng-1) - i;
            for(int j = 0 ; j<leng; j++)
            {
                m[j][reverse] = matrix[i][j];
            }
        }
        matrix = m;
    }
};
