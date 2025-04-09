class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            int len = nums.size();
            int ans = 0;
            map<int, int> count;
            vector<int> number;
    
            for(int i = 0; i<len; i++)
            {
                if(++count[nums[i]] == 1)
                {
                    number.push_back(nums[i]);
                }
                if(nums[i] < k)
                {
                    return -1;
                }
            }
    
            len = number.size();
            sort(number.begin(), number.end());
    
            for(int i = len-1; i>=0; i--)
            {
                if(number[i]>k)
                {
                    ans++;
                }
                else
                {
                    break;
                }
            }
    
            return ans;
        }
    };