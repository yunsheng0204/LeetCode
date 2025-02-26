class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            long long int len = nums.size();
            long long int max_temp = nums[0];
            long long int max_ans = nums[0];
            long long int min_temp = nums[0];
            long long int min_ans = nums[0];
    
            for(int i = 1; i<len; i++)
            {
                max_temp = max(max_temp + nums[i], (long long int)nums[i]);
                min_temp = min(min_temp + nums[i], (long long int)nums[i]);
    
                max_ans = max(max_ans, max_temp);
                min_ans = min(min_ans, min_temp);
            }
            return max(abs(max_ans), abs(min_ans));
        }
    };