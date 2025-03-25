class Solution {
    public:
        bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
            int len = rectangles.size();
            int len_x;
            int len_y;
            vector<vector<int>> x(len, vector<int> (2, 0));
            vector<vector<int>> y(len, vector<int> (2, 0));
            vector<vector<int>> x_merge;
            vector<vector<int>> y_merge;
            int count_x = 0;
            int count_y = 0;
            
            for(int i = 0; i<len; i++)
            {
                x[i][0] = rectangles[i][0];
                x[i][1] = rectangles[i][2];
    
                y[i][0] = rectangles[i][1];
                y[i][1] = rectangles[i][3];
            }
            sort(x.begin(), x.end());
            sort(y.begin(), y.end());
    
            for(int i = 1; i<len; i++)
            {
                if(x[i][0] - x[i-1][1] >= 0)
                {
                    x_merge.push_back(x[i-1]);
                }
                else
                {
                    x[i][0] = x[i-1][0];
                    x[i][1] = max(x[i-1][1], x[i][1]);
                }
    
                if(y[i][0] - y[i-1][1] >= 0)
                {
                    y_merge.push_back(y[i-1]);
                }
                else
                {
                    y[i][0] = y[i-1][0];
                    y[i][1] = max(y[i-1][1], y[i][1]);
                }
            }
    
            x_merge.push_back(x[len-1]);
            y_merge.push_back(y[len-1]);
    
            len_x = x_merge.size();
            len_y = y_merge.size();
    
            if(len_x > 2 || len_y > 2)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    };