
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int len = nums.size();
        long long sum = 0;
        long long target = 0;
        vector<long long> prefix(len + 1, 0);
        int ans = -1;

        unordered_map<long long, int> mp;

        mp[0] = 0;

        for(int i = 0; i < len; i++)
        {
            sum += nums[i];
            prefix[i + 1] = prefix[i] + nums[i];
            mp[prefix[i + 1]] = i + 1;
        }

        target = sum - x;

        if(target < 0)
        {
            return -1;
        }

        if(target == 0)
        {
            return len;
        }

        for(int i = 1; i <= len; i++)
        {
            long long need = prefix[i] - target;

            if(mp.count(need))
            {
                int j = mp[need];

                if(j < i)
                {
                    ans = max(ans, i - j);
                }
            }
        }

        if(ans != -1)
        {
            ans = len - ans;
        }

        return ans;
    }
};