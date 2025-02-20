class Solution {
    public:
        string findDifferentBinaryString(vector<string>& nums) {
            if(nums[0] == "0")
            {
                return "1";
            }
            int len = nums.size();
            int temp_len;
            int count;
            long long int max = pow(2,len) - 1;
            long long int temp_2 = 2^len - 1;
            
            vector<bool> check(max + 1, false);
            string temp = "";
            string ans = "";
    
            for(int i = 0; i<len; i++)
            {
                temp = nums[i];
                temp_len = temp.size();
    
                count = 1;
                temp_2 = 0;
    
                for(int j = temp_len-1; j>=0; j--)
                {
                    temp_2 += count * (temp[j] - '0');
                    count *= 2;
                }
                check[temp_2] = true;
            }
    
            for(long long int i = 0; i<max; i++)
            {
                if(check[i] == false)
                {
                    if(i == 0)
                    {
                        for(int j = 0; j<len; j++)
                        {
                            ans += "0";
                        }
                    }
                    while(i>=1)
                    {
                        if(i%2 == 1)
                        {
                            ans = "1" + ans;
                        }
                        else
                        {
                            ans = "0" + ans;
                        }
                        i /= 2;
                    }
                    break;
                }
            }
            int check_len = ans.size();
            for(int i = check_len; i<len; i++)
            {
                ans = "0" + ans;
            }
            return ans;
        }
    };