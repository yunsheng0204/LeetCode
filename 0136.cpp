class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> number;
        bool check = 0;

        int temp = 0;
        while(nums.size()!=0)
        {
            temp = nums[0];
            nums.erase(nums.begin());

            for(int i =0; i<number.size(); i++)
            {
                if(temp == number[i])
                {
                    number.erase(number.begin() + i);
                    check = 1;
                    break;
                }
            }
            if(check == 0)
            {
                number.push_back(temp);
            }
            check = 0;
        }
        return number[0];
    }
};