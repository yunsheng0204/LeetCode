class Solution {
    public:
        int maximumCount(vector<int>& nums) {
            int len = nums.size();
            int count = 0;
            int count_zero = 0;
            int i = 0;
    
            for(i = 0; i<len; i++)
            {
                if(nums[i]<0)
                {
                    count++;
                }
                else
                {
                    break;
                }
            }
            for(i = i; i<len; i++)
            {
                if(nums[i] == 0)
                {
                    count_zero++;
                }
                else
                {
                    break;
                }
            }
    
            return max(count, len - count - count_zero);
        }
    };