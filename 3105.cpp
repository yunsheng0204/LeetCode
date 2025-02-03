class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int len = nums.size();
        int inc_count = 1;
        int dec_count = 1;
        int max = 1;

        for(int i = 1; i<len; i++)
        {
            if(nums[i] > nums[i-1])
            {
                if(++inc_count > max)
                {
                    max = inc_count;
                }
                dec_count = 1;
            }
            else if(nums[i] < nums[i-1])
            {
                if(++dec_count > max)
                {
                    max = dec_count;
                }
                inc_count = 1;
            }
            else if(nums[i] == nums[i-1])
            {
                dec_count = 1;
                inc_count = 1;
            }
        }
        return max;
    }
};