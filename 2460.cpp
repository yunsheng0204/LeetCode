class Solution {
    public:
        vector<int> applyOperations(vector<int>& nums) {
            int len = nums.size();
            vector<int>ans(len, 0);
            int index = 0;
    
            len--;
            for(int i = 0; i<len; i++)
            {
                if(nums[i] == nums[i+1])
                {
                    nums[i] *= 2;
                    nums[i + 1] = 0;
                }
                if(nums[i] != 0)
                {
                    ans[index] = nums[i];
                    index++;
                }
            }
            if(nums[len] != 0)
            {
                ans[index] = nums[len];
            }
            return ans;
        }
    };