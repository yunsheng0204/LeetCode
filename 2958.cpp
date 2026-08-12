class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int len = nums.size();
        map<int, int> count;
        int begin = 0;
        int ans = 0;

        for(int i = 0; i<len; i++)
        {
            if(++count[nums[i]] > k)
            {
                ans = max(ans, i - begin);
                while(count[nums[i]] > k)
                {
                    count[nums[begin++]]--;
                }
            }
        }
        ans = max(ans, len - begin);
        return ans;
    }
};