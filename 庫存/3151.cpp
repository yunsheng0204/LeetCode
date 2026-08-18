class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int len = nums.size();

        bool odd_evan;

        if(nums[0] % 2 == 0)
        {
            for(int i = 1; i<len; i++)
            {
                if(i % 2 == 1)
                {
                    if(nums[i] % 2 == 0)
                    {
                        return false;
                    }
                }
                else
                {
                    if(nums[i] % 2 == 1)
                    {
                        return false;
                    }
                }
            }
        }
        else
        {
            for(int i = 1; i<len; i++)
            {
                if(i % 2 == 1)
                {
                    if(nums[i] % 2 == 1)
                    {
                        return false;
                    }
                }
                else
                {
                    if(nums[i] % 2 == 0)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};