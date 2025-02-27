class Solution {
    public:
        int lenLongestFibSubseq(vector<int>& arr) {
            int len = arr.size();
    
            int ans = 0;
    
            int count = 0;
    
            int t;
    
            long long int left, right;
    
            unordered_map<long long int, int> mapp;
    
            vector<vector<int>> record(len, vector<int>(len, 0));
    
            for(int i = 0; i<len; i++)
            {
                mapp[arr[i]] = i+1;
            }
    
            for(int i = 0; i<len-1; i++)
            {
                for(int j = i + 1; j<len; j++)
                {
                    left = arr[i];
                    right = arr[j];
    
                    if(right-left >= left)
                    {
                        record[i][j] = 2;
                    }
                    else if(mapp[right-left] == 0)
                    {
                        record[i][j] = 2;
                    }
                    else
                    {
                        t = left;
                        left = right-left;
                        right = t;
                        
                        if(record[mapp[left]-1][mapp[right]-1] == 0)
                        {
                            record[i][j] = 2;
                        }
                        else
                        {
                            record[i][j] = record[mapp[left]-1][mapp[right]-1] + 1;
                            ans = max(ans, record[i][j]);
                        }
                    }
                }
            }
            return ans;
        }
    };