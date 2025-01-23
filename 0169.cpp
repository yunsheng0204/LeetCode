class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        int time = len/2;
        int i = 0;
        int max = 0;
        int max_index = 0;
        bool check = 0;
        vector<int> number;
        vector<int> count;

        while(i<len)
        {
            for(int j = 0; j<number.size(); j++)
            {
                if(number[j] == nums[i])
                {
                    count[j]++;
                    check = 1;
                    if(count[j]>time)
                    {
                        return number[j];
                    }
                }
            }
            if(check == 1)
            {
                check = 0;
            }
            else
            {
                number.push_back(nums[i]);
                count.push_back(1);
            }
            i++;
        }
        for(int j = 0; j<count.size(); j++)
        {
            if(count[j]>max)
            {
                max = count[j];
                max_index = j;
            }
        }
        return number[max_index];
    }
};