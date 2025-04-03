class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            int len = nums.size();
            long long ans = 0;
            long long diff = 0;
            int prefixMax = nums[0];
            vector<int> suffixMax(len, 0);
    
            suffixMax[len - 1] = nums[len - 1];
            for (int i = len - 2; i >= 0; i--) 
            {
                suffixMax[i] = max(nums[i], suffixMax[i + 1]);
            }
    
            for (int j = 1; j < len - 1; j++) 
            {
                diff = (long long)(prefixMax - nums[j]);
                if (diff > 0) 
                {
                    ans = max(ans, diff * suffixMax[j + 1]);
                }
                prefixMax = max(prefixMax, nums[j]);
            }
            return ans;
        }
    };
    