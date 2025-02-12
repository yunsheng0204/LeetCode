class Solution {
    public:
        int maximumSum(vector<int>& nums) {
            int len = nums.size();
            int temp = 0;
            int temp_sum = 0;
            int ans = -1;
    
            map<int, int> count;
            map<int, int> mapp;
            map<int, int> mapp2;
    
            for(int i = 0; i<len; i++)
            {
                temp = nums[i];
                while(temp > 9)
                {
                    temp_sum += temp % 10;
                    temp /= 10;
                }
                temp_sum += temp;
                if(++count[temp_sum] > 1)
                {
                    if(nums[i] > mapp[temp_sum])
                    {
                        mapp2[temp_sum] = mapp[temp_sum];
                        mapp[temp_sum] = nums[i];
                        
                        ans = max(ans, mapp[temp_sum] + mapp2[temp_sum]);
                    }
                    else if(nums[i] > mapp2[temp_sum])
                    {
                        mapp2[temp_sum] = nums[i];
    
                        ans = max(ans, mapp[temp_sum] + mapp2[temp_sum]);
                    }
                }
                else
                {
                    mapp[temp_sum] = nums[i];
                }
                temp_sum = 0;
            }
            return ans;
            
        }
    };