class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            long long ans = 0;
            int len = nums.size();
            for(int i = 0; i<len; i++)
            {
                for(int j = i+1; j<len; j++)
                {
                    for(int k = j+1; k<len; k++)
                    {
                        ans = max(ans, (long long)(nums[i] - nums[j]) * nums[k]);
                    }
                }
            }
            return ans;
        }
    };