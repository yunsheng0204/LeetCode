class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0;
        int len = nums.size();
        int mini = 0;
        int min_index = 0;
        while(check_dec(nums) == false)
        {
            ans++;
            len = nums.size();
            mini = nums[0] + nums[1];
            min_index = 1;
            for(int i = 2; i<len; i++)
            {
                if(mini > nums[i] + nums[i-1])
                {
                    mini = nums[i] + nums[i-1];
                    min_index = i;
                }
            }
            nums[min_index - 1] += nums[min_index];
            nums.erase(nums.begin() + min_index);
        }

        return ans;
    }

    bool check_dec(vector<int>& nums)
    {
        int len = nums.size();
        for(int i = 1; i<len; i++)
        {
            if(nums[i-1] > nums[i])
            {
                return false;
            }
        }
        return true;
    }
};