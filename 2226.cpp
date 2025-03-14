class Solution {
    public:
        int maximumCandies(vector<int>& candies, long long k) {
            long long ans = 0;
            long long len = candies.size();
            long long left, middle, right;
            long long temp;
            long long count = 0;
    
            sort(candies.begin(), candies.end());
    
            // for(long long i = 0; i<len; i++)
            // {
            //     cout<<candies[i]<<" ";
            // }
            // cout<<endl;
    
            left = 1;
            right = candies[len - 1];
            while(left<=right)
            {
                middle = (left + right) / 2;
                count = 0;
    
                for(long long i = len-1; i>=0; i--)
                {
                    count += candies[i] / middle;
                    if(count >= k)
                    {
                        break;
                    }
                }
                if(count >= k)
                {
                    left = middle + 1;
                    ans = middle;
                }
                else
                {
                    right = middle - 1;
                }
                // cout<<left<<" "<<right<<endl;
            }
            return ans;
        }
    };