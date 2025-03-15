class Solution {
    public:
        int minCapability(vector<int>& nums, int k) {
            long long int len = nums.size();
    
            long long int index = 0;
            long long int count = 0;
            long long int ans = 0;
            long long int left = nums[0], right = nums[0], mid;
            
    
            for(long long int i = 0; i<len; i++)
            {
                left = min((long long)nums[i], left);
                right = max((long long)nums[i], right);
            }
    
            while(left<=right)
            {
                mid = (left + right) / 2;
                if( check_enough(nums, k, mid, len) == false)
                {
                    left = mid + 1;
                }
                else
                {
                    ans = mid;
                    right = mid - 1;
                }
            }
    
            return ans;
        }
    
        bool check_enough(vector<int>& nums, int k, long long int mid, long long int len)
        {
            long long int count = 0;
            long long int index = 0;
    
            while(index<len)
            {
                if(nums[index] <= mid)
                {
                    count++;
                    index +=2;
                }
                else
                {
                    index += 1;
                }
            }
            if(count>=k)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    };