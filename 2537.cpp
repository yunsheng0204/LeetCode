class Solution {
    public:
        long long countGood(vector<int>& nums, int k) {
            map<int, int> freq;
            int len = nums.size();
            int left = 0;
            int right = 0;
            int temp = 0;
            long long ans = 0;
            long long pairs = 0;
    
            for(right = 0; right < len; right++) 
            {
                temp = nums[right];
                pairs += freq[temp];
                freq[temp]++;
    
                while (pairs >= k) 
                {
                    ans += (len - right);
                    freq[nums[left]]--;
                    pairs -= freq[nums[left]];
                    left++;
                }
            }
            return ans;
        }
    };