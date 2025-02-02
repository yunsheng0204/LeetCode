class Solution {
public:
    bool check(vector<int>& nums) {
        int len = nums.size();
        vector<int> s = nums;
        int head;
        int count = 0;

        sort(s.begin(), s.end());
        for(int i = 0; i<len; i++)
        {
            if(nums[0] == s[i])
            {
                head = i;
                count++;
                while(head + count < len)
                {
                    if(s[head + count] == s[head])
                    {
                        count++;
                    }
                    else
                    {
                        break;
                    }
                }
                break;
            }
        }
        flag:
        for(int i = 0; i<len; i++)
        {
            if(head + i == len)
            {
                head = head - len;
            }
            if(nums[i] != s[head + i])
            {
                if(--count != 0)
                {
                    head++;
                    goto flag;
                }
                return false;
            }
        }
        return true;
    }
};