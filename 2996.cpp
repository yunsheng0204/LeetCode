class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int len = 1;
        int sum = 0;
        bool con = true;
        
        vector<bool> exist(52, false);
        exist[nums[0]] = true;

        for(int i = 0; i<nums.size()-1; i++)
        {
            exist[nums[i+1]] = true;

            if(nums[i+1] == nums[i] + 1 && con == true)
            {
                ++len;
            }
            else if(con == false)
            {
                continue;
            }
            else
            {
                con = false;
            }
        }

        sum = (nums[0] + nums[0] + len - 1) * len / 2;

        if(sum > 50)
        {
            return sum;
        }

        while(exist[sum] == true)
        {
            if(++sum == 51)
            {
                return sum;
            }
        }

        return sum;

    }
};