class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int len = digits.size();
        int ans = 0;
        vector<int> count(10, 0);

        for(int i = 0; i<len; i++)
        {
            count[digits[i]]++;
        }

        for(int i = 1; i<10; i++)
        {
            if(count[i] > 0)
            {
                count[i]--;
                for(int j = 0; j<10; j++)
                {
                    if(count[j] > 0)
                    {
                        count[j]--;
                        for(int k = 0; k<10; k+=2)
                        {
                            if(count[k] > 0)
                            {
                                ans++;
                            }
                        }
                        count[j]++;
                    }
                }
                count[i]++;
            }
        }
        return ans;
    }
};