class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            int len = nums.size();
            int count = 0;
            long long int temp = 0;
            vector<int>::iterator beg = nums.begin();
    
            sort(beg, nums.end());
            for(int i = 0; i<len; i++)
            {
                if(nums[i] >= k)
                {
                    len = i;
                    break;
                }
            }
    
            while(len > 2)
            {
                count++;
                temp = (long long int)nums[0] * 2 + nums[1];
                nums.erase(beg, beg+2);
                len -= 2;
    
                if(temp < k)
                {
                    int left = 0;
                    int right = len - 1;
                    int mid = (right + left) / 2 ;
                    int i = len;
    
                    while (left <= right) 
                    {
                        mid = (right + left) / 2;
                        if(nums[mid] < temp)
                        {
                            left = mid + 1;
                        }
                        else
                        {
                            i = mid;
                            right = mid - 1;
                        }
                    }
                    nums.insert(beg + i, temp);
                    len++;
                }
            }
            if(nums[0] < k)
            {
                if(len == 1)
                {
                    return count + 1;
                }
                else if((long long int)nums[0] * 2 + nums[1] < k)
                {
                    return count + 2;
                }
                else if((long long int)nums[0] * 2 + nums[1] >= k)
                {
                    return count + 1;
                }
            }
            return count;
        }
    };