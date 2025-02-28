class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
       int sum = nums[0]; 
       int max = 0;
       int len = nums.size(); 

        for(int i = 1; i<len; i++)
        {
            if(nums[i] > nums[i-1])
            {
                sum += nums[i];
            }
            else
            {
                if(max < sum)
                {
                    max = sum;
                }
                sum = nums[i];
            }
        }
        if(max < sum)
        {
            max = sum;
        }
        return max;
    }
};