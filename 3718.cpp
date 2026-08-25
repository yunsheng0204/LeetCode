class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<bool> exist(101, false);
        int len = nums.size();
        long long ans = k;

        for(int i = 0; i<len; i++)
        {
            exist[nums[i]] = true;
        }

        while(exist[ans] == true)
        {
            ans += k;
            if(ans > 100)
            {
                return ans;
            }
        }

        return ans;
    }
};