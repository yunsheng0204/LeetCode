class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            
            int count = 0;
            int l;
    
            vector<int> diff;
    
            for(int i = 0; i<k-1; i++)
            {
                colors.push_back(colors[i]);
            }
    
            int len = colors.size();
    
            diff.push_back(-1);
    
            for(int i = 0; i<len - 1; i++)
            {
                if(colors[i] + colors[i+1] != 1)
                {
                    diff.push_back(i);
                }
            }
    
            diff.push_back(len-1);
    
            len = diff.size();
    
            if(len == 0)
            {
                return 0;
            }
            else
            {
                for(int i = 1;i<len; i++)
                {
                    l = diff[i] - diff[i-1];
                    if(l>=k)
                    {
                        count += l - k + 1;
                    }
                }
            }
            return count;
        }
    };