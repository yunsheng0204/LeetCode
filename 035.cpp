class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        int left = 0;
        int right = len;
        int mid = (left + right) / 2;

        if(target>nums[len-1])
        {
            return len;
        }
        if(target<nums[0])
        {
            return 0;
        }

        while(1)
        {
            if(left>right)
            {
                break;
            }   
            if(target>nums[mid])
            {
                left = mid + 1;
                mid = (left + right) / 2;
                continue;
            }
            else
            {
                right = mid - 1;
                mid = (left + right) / 2;
                continue;
            }
        }
        return left;
    }
};
