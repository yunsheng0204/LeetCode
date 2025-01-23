class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int sum[3] = {0};
        int pos = 0;

        for(int i = 0; i<len; i++)
        {
            sum[nums[i]]++;
        }
        for(int i = 0; i<sum[0]; i++)
        {
            nums[pos++] = 0;
        }
        for(int i = 0; i<sum[1]; i++)
        {
            nums[pos++] = 1;
        }
        for(int i = 0; i<sum[2]; i++)
        {
            nums[pos++] = 2;
        }
    }
};