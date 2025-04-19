class Solution {
    public:
        long long countFairPairs(vector<int>& nums, int lower, int upper) {
            int len = nums.size();
            long long ans = 0;
            int left, right;
    
    
            sort(nums.begin(), nums.end());
    
            for(int i = 0; i<len; i++)
            {
                left = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
                right = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin();
                ans += (right-left);
            }
    
            return ans;
        }
    };