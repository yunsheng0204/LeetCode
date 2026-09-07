class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int mini = INT_MAX;
        int len = nums.size();
        int ans = 0;

        for(int i = 0; i<len; i++)
        {
            for(int j = 0; j<len; j++)
            {
                if(nums[i] > nums[j])
                {
                    swap(nums[i], nums[j]);
                }
            }
        }

        for(int i = 0 ;i<len; i++)
        {
            for(int j = i+1; j<len; j++)
            {
                for(int k = j+1; k<len; k++)
                {
                    if(mini > abs(target - (nums[i] + nums[j] + nums[k])))
                    {
                        mini = abs(target - (nums[i] + nums[j] + nums[k]));
                        ans = (nums[i] + nums[j] + nums[k]);
                    }
                }
            }
        }

        return ans;
    }
};