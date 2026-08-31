class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int len = nums.size();
        int min_index = 0, max_index = 0;
        int max_num = nums[0], min_num = nums[0];
        int ans = 0;
        
        for(int i = 1; i<len; i++)
        {
            if(min_num > nums[i])
            {
                min_index = i;
                min_num = nums[i];
            }
            if(max_num < nums[i])
            {
                max_index = i;
                max_num = nums[i];
            }
        }
        
    
        
        ans = min(max(max_index + 1, min_index + 1), max(len - max_index, len - min_index));
        ans = min(ans, min(len - max_index, max_index + 1) + min(len - min_index, min_index + 1));
        
        return ans;
    }
};