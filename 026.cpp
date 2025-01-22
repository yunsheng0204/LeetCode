class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int sum = 0;
        int repeat = 0;
        int pos = 0;
        bool lock = 0;
        int temp = 0;
        for(int i = 0;i<nums.size();i++)
        {
            if(i != 0)
            {
                if(nums[i] == nums[i-1])
                {
                    repeat = nums[i];
                    nums[i] = -100;
                    cout<<repeat<<"第一次重複"<<endl;
                    while( i+1 < nums.size())
                    {
                        if(nums[i+1] == repeat)
                        {
                            i++;
                            nums[i] = -100;
                            cout<<repeat<<"重複"<<endl;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                else
                {
                    sum++;
                }
            }
            else
            {
                sum++;
            }
            
        }
        for(int i = 1;i<nums.size();i++)
        {
            if(nums[i] == -100 && lock == 0)
            {
                pos = i;
                lock = 1;
                cout<<"儲存"<<i<<endl;
            }
        }
        for(int i = pos + 1;i<nums.size();i++)
        {
            if(nums[i] != -100 && lock == 1)
            {
                temp = nums[pos];
                nums[pos] = nums[i] ;
                nums[i] = temp;
                pos++;
            }
        }
        return sum;
    }
};