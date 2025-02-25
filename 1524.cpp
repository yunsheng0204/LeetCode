class Solution {
    public:
        int numOfSubarrays(vector<int>& arr) {
            long long int even_count = 0;
            long long int odd_count = 0;
            long long int ans = 0;
            long long int t = (pow(10, 9) + 7);
    
            long long int te = 0;
    
            long long int len = arr.size();
    
            for(long long int i = 0; i<len; i++)
            {
                if(arr[i]%2 == 0)
                {
                    even_count++;
                }
                else
                {
                    te = odd_count;
                    odd_count = even_count;
                    even_count = te;
    
                    odd_count++;
                }
                ans = ans + odd_count;
            }
    
            return ans % t;
        }
    };