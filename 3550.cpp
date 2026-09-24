class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int len = nums.size();
        int sum = 0;
        int temp = 0;

        for(int i = 0; i<len; i++)
        {
            sum = 0;
            temp = nums[i];
            while(temp >= 1)
            {
                sum += temp % 10;
                temp = temp / 10;
            }

            if(sum == i)
            {
                return i;
            }
        }

        return -1;
    }
};