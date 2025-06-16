class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int len = nums.size();
        int maxi = -1;

        for(int i = 0; i<len; i++)
        {
            for(int j = i + 1; j<len; j++)
            {
                if(nums[j] > nums[i])
                {
                    maxi = max(maxi, nums[j] - nums[i]);
                }
            }
        }

        return maxi;
    }
};