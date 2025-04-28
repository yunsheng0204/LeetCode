class Solution {
    public:
        long long countSubarrays(vector<int>& nums, long long k) {
            int len = nums.size();
            long long ans = 0;
            int left = 0;
            int right = -1;
            long long temp_sum = 0;
    
            for(right = 0; right<len; right++)
            {
                temp_sum += nums[right];
                while (left <= right && temp_sum * (right - left + 1) >= k)
                {
                    temp_sum -= nums[left];
                    left++;
                }
                ans += (right - left + 1);
            }
    
            return ans;
    
        }
    };