class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            int len = nums.size();
            int sum = 0;
            
            for(int i = 0; i < len; i++) 
            {
                sum += nums[i];
            }
    
            if(sum % 2 == 1) 
            {
                return false;
            }
    
            int target = sum / 2;
            int num;
            vector<bool> dp(target + 1, false);
            dp[0] = true;
    
            for(int i = 0; i < len; i++)
            {
                num = nums[i];
                for(int j = target; j >= num; j--)
                {
                    dp[j] = dp[j] || dp[j - num];
                }
            }
            return dp[target];
        }
    };
    