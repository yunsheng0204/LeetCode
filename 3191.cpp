class Solution {
    public:
        int minOperations(vector<int>& nums) {
            int len = nums.size();
            int ans = 0;
            for(int i = 0; i<len-2; i++)
            {
                if(nums[i] == 0)
                {
                    ans++;
                    nums[i+1] = (nums[i+1] + 1) % 2;
                    nums[i+2] = (nums[i+2] + 1) % 2;
                }
            }
    
            if(nums[len-1] == 0 || nums[len-2] == 0)
            {
                return -1;
            }
            return ans;
        }
    };