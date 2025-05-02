class Solution {
    public:
        string pushDominoes(string dominoes) {
            int len = dominoes.size();
            int num_right = 0;
            int num_left = 0;
            long long count_right_te = 0;
            long long count_left_te = 0;
    
            vector<long long> count_right(len, 0);
            vector<long long> count_left(len, 0);
    
            string ans = "";
    
            for(int i = 0; i<len; i++)
            {
                if(dominoes[i] == 'R')
                {
                    count_right_te = len;
                }
                else if(dominoes[i] == 'L')
                {
                    count_right_te = 0;
                }
                count_right[i] = count_right_te;
                if(count_right_te > 0)
                {
                    count_right_te -= 1;
                }
            }
    
            for(int i = len - 1; i>=0; i--)
            {
                if(dominoes[i] == 'L')
                {
                    count_left_te = len;
                }
                else if(dominoes[i] == 'R')
                {
                    count_left_te = 0;
                }
                count_left[i] = count_left_te;
                if(count_left_te > 0)
                {
                    count_left_te -= 1;
                }
            }
    
            for(int i = 0; i<len; i++)
            {
                if(count_left[i] > count_right[i])
                {
                    ans += 'L';
                }
                else if(count_left[i] < count_right[i])
                {
                    ans += 'R';
                }
                else if(count_left[i] == count_right[i])
                {
                    ans += '.';
                }
            }
    
            return ans;
        }
    };