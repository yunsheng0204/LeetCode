class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int len = blocks.size();
            int t = len - k;
            int white_count = 0;
            int ans;
    
            for(int i = 0; i<k ;i++)
            {
                if(blocks[i] == 'W')
                {
                    white_count++;
                }
            }
            ans = white_count;
    
            for(int i = 0; i<t; i++)
            {
                if(blocks[i] == 'W')
                {
                    white_count--;
                }
                if(blocks[i + k] == 'W')
                {
                    white_count++;
                }
                ans = min(ans, white_count);
            }
            return ans;
        }
    };