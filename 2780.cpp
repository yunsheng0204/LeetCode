class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            int len = nums.size();
            int max_appear = 0;
            int max_number = 0;
            int count_appear = 0;
            map<int ,int> count;
    
            for(int i = 0; i<len; i++)
            {
                if(++count[nums[i]] > max_appear)
                {
                    max_appear = count[nums[i]];
                    max_number = nums[i];
                }
            }
    
            for(int i = 0; i<len; i++)
            {
                if(nums[i] == max_number)
                {
                    count_appear++;
                    max_appear--;
                }
                // cout<<i<<" "<<count_appear<<" "<<max_appear<<endl;
                if(count_appear > (i+1)/2 && max_appear > (len-i-1)/2)
                {
                    return i;
                }
            }
    
            return -1;
        }
    };