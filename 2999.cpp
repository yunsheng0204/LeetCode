class Solution {
    public:
        long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
    
            return count_(finish, limit, s) - count_(start - 1, limit, s);
    
        }
    
    private:
        long long count_(long long val, int limit, string &s) 
        {
            string temp = to_string(val); 
            int current;
            int prefix_len = temp.size() - s.size();
            
            if (prefix_len < 0) 
            {
                return 0;
            } 
    
            vector<vector<long long>> num_of_way(prefix_len + 1, vector<long long>(2, 0));
            num_of_way[prefix_len][0] = 1;
    
            if(temp.substr(prefix_len) >= s)
            {
               num_of_way[prefix_len][1] = 1;
            }
            else
            {
                num_of_way[prefix_len][1] = 0;
            }
    
            for (int i = prefix_len - 1; i >= 0; i--) 
            {
                current = temp[i] - '0';
    
                num_of_way[i][0] = (limit + 1) * num_of_way[i + 1][0];
    
                if (current <= limit) 
                {
                    num_of_way[i][1] = (long long) current * num_of_way[i + 1][0] + num_of_way[i + 1][1];
                } 
                else 
                {
                    num_of_way[i][1] = (long long)(limit + 1) * num_of_way[i + 1][0];
                }
            }
            return num_of_way[0][1]; 
        }
    };