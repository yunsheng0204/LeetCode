class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> final_ans(n);
        int number = n;
        int ans[n][n];
        int count = 0;
        int row = 0, col = -1;
        int direction = 0;
        for(int i = 0;i<n;i++)
        {
            col++;
            ans[0][i] = ++count;
        }
        n--;
        for(int c = n; c>0; c--)
        {
            direction++;
            switch( direction%4 )
            {
                case 1:
                    for(int sc = 0;sc<2;sc++)
                    {
                        switch( sc )
                        {
                            case 0:
                                for(int i = 0;i<c; i++)
                                {
                                    row++;
                                    ans[row][col] = ++count; 
                                }
                                break;
                            case 1:
                                for(int i = 0;i<c; i++)
                                {
                                    col--;
                                    ans[row][col] = ++count;
                                }
                                break;
                        }
                    }
                    break;
                    
                case 2:
                    for(int sc = 0;sc<2;sc++)
                    {
                        switch( sc )
                        {
                            case 0:
                                for(int i = 0;i<c; i++)
                                {
                                    row--;
                                    ans[row][col] = ++count; 
                                }
                                break;
                            case 1:
                                for(int i = 0;i<c; i++)
                                {
                                    col++;
                                    ans[row][col] = ++count;
                                }
                                break;
                        }
                    }
                    break;
                case 3:
                    for(int sc = 0;sc<2;sc++)
                    {
                        switch( sc )
                        {
                            case 0:
                                for(int i = 0;i<c; i++)
                                {
                                    row++;
                                    ans[row][col] = ++count; 
                                }
                                break;
                            case 1:
                                for(int i = 0;i<c; i++)
                                {
                                    col--;
                                    ans[row][col] = ++count;
                                }
                                break;
                        }
                    }
                    break;
                case 0:
                    for(int sc = 0;sc<2;sc++)
                    {
                        switch( sc )
                        {
                            case 0:
                                for(int i = 0;i<c; i++)
                                {
                                    row--;
                                    ans[row][col] = ++count; 
                                }
                                break;
                            case 1:
                                for(int i = 0;i<c; i++)
                                {
                                    col++;
                                    ans[row][col] = ++count;
                                }
                                break;
                        }
                    }
                    break;
            }
        }
        // for(int i= 0;i<number;i++)
        // {
        //     for(int j = 0; j<number;j++)
        //     {
        //         cout<<ans[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int i= 0;i<number;i++)
        {
            for(int j = 0; j<number;j++)
            {
                final_ans[i].push_back(ans[i][j]);
            }
        }
        return final_ans;
    }
};