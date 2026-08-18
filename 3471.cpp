class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int ans = -1;
        vector<int> count(51, 0);
        if(nums.size() == k)
        {
            for(int i = 0; i<k; i++)
            {
                ans = max(ans, nums[i]);
            }
        }
        else
        {
            for(int i = 0; i<nums.size(); i++)
            {
                count[nums[i]]++;
            }
            if(k == 1)
            {
                for(int i = 0; i<51; i++)
                {
                    if(count[i] == 1)
                    {
                        ans = max(ans, i);
                    }
                }
            }
            else if(count[nums[0]] != 1 && count[nums[nums.size()-1]] != 1)
            {
                return -1;
            }
            else if(count[nums[0]] != 1)
            {
                return nums[nums.size()-1];
            }
            else if(count[nums[nums.size()-1]] != 1)
            {
                return nums[0];
            }
            else
            {
                ans = max(nums[0], nums[nums.size()-1]);
            }
        }
        return ans;
    }
};