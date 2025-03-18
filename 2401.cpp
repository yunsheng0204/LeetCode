class Solution {
    public:
        int longestNiceSubarray(vector<int>& nums) {
            int len = nums.size();
            int ans = 1;
            int left = 0, right = 1;
            int temp = 0;
            for(int i = 1; i<len; i++)
            {
                right = i;
                
                for(int j = left; j<right; j++)
                {
                    // cout<<bitset<8>(nums[j])<<" "<<bitset<8>(nums[right])<<" "<<(nums[j] & nums[right])<<endl;
                    if((nums[right] & nums[j]) != 0)
                    {
                        left = j + 1;
                    }
                }
                // cout<<left<<" "<<right<<endl;
                temp = right - left + 1;
                ans = max(ans, temp);
            }
            return ans;
        }
    };