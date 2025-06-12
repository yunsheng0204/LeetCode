class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int len = nums.size();
        int ans = 0;

        for(int i = 1; i<len; i++)
        {
            ans = max(abs(nums[i] - nums[i-1]), ans);
        }

        ans = max(abs(nums[0] - nums[len - 1]), ans);

        return ans;
    }
};