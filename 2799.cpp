class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            int len = nums.size();
            int total = 0;
            map<int,int> count;
            int total_now = 0;
            int ans = 0;
    
            for(int i = 0; i<len; i++)
            {
                if(++count[nums[i]] == 1)
                {
                    total++;
                }
            }
    
            for(int left = 0; left<len; left++)
            {
                total_now = 0;
                map<int,int> temp;
                for(int right = left; right<len; right++)
                {
                    if(++temp[nums[right]] == 1)
                    {
                        if(++total_now == total)
                        {
                            ans += (len - right);
                            break;
                        }
                    }
                }
            }
            return ans;
        }
    };