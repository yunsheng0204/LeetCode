class Solution {
    public:
        vector<int> closestPrimes(int left, int right) {
            int min = 10000;
            int min_index;
            int len = right - left + 1;
            int temp = sqrt(right);
            int temp2;
    
            vector<int> q;
            vector<bool> primes(right + 1, true);
            vector<int> ans(2, -1);
    
    
            primes[0] = false;
            primes[1] = false;
            for(int i = 2; i<=temp; i++)
            {
                if(primes[i] == true)
                {
                    temp2 = i;
                    while(temp2 + i <= right)
                    {
                        temp2 += i;
                        primes[temp2] = false;
                    }
                }
            }
    
            for(int i = left; i<=right; i++)
            {
                if(primes[i] == true)
                {
                    q.push_back(i);
                }
            }
            
    
    
            len = q.size() - 1;
            // for(int i = 0; i<len; i++)
            // {
            //     cout<<q[i]<<" ";
            // }
    
            if(len <= 0)
            {
                return ans;
            }
    
            for(int i = 0; i<len; i++)
            {
                if(min > q[i + 1] - q[i])
                {
                    min = q[i + 1] - q[i];
                    ans[0] = q[i];
                    ans[1] = q[i+1];
                }
            }
    
            return ans;
        }
    };