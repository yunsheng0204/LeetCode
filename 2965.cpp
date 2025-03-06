class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            vector<int> ans(2, 0);
            int len = grid.size();
            vector<int> count(len * len, 0);
    
            for(int i = 0; i<len; i++)
            {
                for(int j = 0; j<len; j++)
                {
                    if(++count[grid[i][j]-1] == 2)
                    {
                        ans[0] = grid[i][j];
                    }
                }
            }
            
            len = count.size();
    
            for(int i = 0; i<len; i++)
            {
                if(count[i] == 0)
                {
                    ans[1] = i+1;
                    break;
                }
            }
    
            return ans;
        }
    };