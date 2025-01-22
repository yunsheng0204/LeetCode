class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int *val;
        int *val2;
        val = new int [10];
        val2 = new int [10];
        for(int i = 0; i<10; i++)
        {
            val[i] = 0;
            val2[i] = 0;
        }

        for(int i = 0; i<9; i++)
        {
            for(int j = 0; j<9; j++)
            {
                if(board[i][j] != '.')
                {
                    val[board[i][j]-48]++;
                    if(val[board[i][j]-48] == 2)
                    {
                        return false;
                    }
                }
                if(board[j][i] != '.')
                {
                    val2[board[j][i]-48]++;
                    if(val2[board[j][i]-48] == 2)
                    {
                        return false;
                    }
                }
            }
            for(int i = 0; i<10; i++)
            {
                val[i] = 0;
                val2[i] = 0;
            }
        }
        for(int i = 0; i<9; i = i + 3)
        {
            for(int j = 0; j<9; j = j + 3)
            {
                for(int i1 = 0; i1<3; i1++)
                {
                    for(int j1 = 0; j1<3; j1++)
                    {
                        if(board[i + i1][j + j1] != '.')
                        {
                            val[board[i + i1][j + j1]-48]++;
                            cout<<board[i + i1][j + j1]<<endl;
                            cout<<val[board[i + i1][j + j1]-48]<<endl;
                            if(val[board[i + i1][j + j1]-48] == 2)
                            {
                                return false;
                            }
                        }
                    }
                }
                for(int i = 0; i<10; i++)
                {
                    val[i] = 0;
                }
            }
        }
        return true;
    }
};