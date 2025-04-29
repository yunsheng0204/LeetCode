class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int k) {
            long long maxi = 0;
            int len = nums.size();
            vector<int> index;
            long long ans = 0;
            int index_len = 0;
            int pre = -1;
    
            for(int i = 0; i<len; i++)
            {
                maxi = max((long long)nums[i], maxi);
            }
            for(int i = 0; i<len; i++)
            {
                if(nums[i] == maxi)
                {
                    index.push_back(i);
                }
            }
            index_len = index.size();
    
            if(index_len < k)
            {
                return 0;
            }
            else
            {
                for(int i = k - 1; i<index_len; i++)
                {
                    ans += (  (long long)(index[i - (k-1)] - pre ) * (long long)(len - index[i]) );
                    pre = index[i - (k-1)];
                }
            }
            return ans;
        }
    };