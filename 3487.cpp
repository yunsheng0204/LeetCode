class Solution {
    public:
        int maxSum(vector<int>& nums) {
            vector<bool> check(101, false);
            int len = nums.size();
            int ans = 0;
            int max_temp = nums[0];
    
            for(int i = 0; i<len; i++)
            {
                max_temp = max(max_temp, nums[i]);
                
                if(nums[i]>0)
                {
                    if(check[nums[i]] == false)
                    {
                        ans += nums[i];
                        check[nums[i]] = true;
                    }
                }
            }
    
            if(ans == 0)
            {
                return max_temp;
            }
            return ans;
        }
    };