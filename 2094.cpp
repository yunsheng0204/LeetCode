class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int len = digits.size();
        vector<int> count(10,0);
        vector<int> ans;

        for(int i = 0; i<len; i++)
        {
            count[digits[i]]++;
        }

        sol(count, ans, 1, 0);

        return ans;
    }

    void sol(vector<int> &count, vector<int> &ans, int index, int temp)
    {
        if(index == 1)
        {
            for(int i = 1; i<10; i++)
            {
                if(count[i]>0)
                {
                    count[i]--;
                    temp = i;
                    sol(count, ans, 2, temp);
                    count[i]++;
                }
            }
        }
        else if(index == 2)
        {
            for(int i = 0; i<10; i++)
            {
                if(count[i]>0)
                {
                    count[i]--;
                    sol(count, ans, 3,temp * 10 + i);
                    count[i]++;
                }
            }
        }
        else if(index == 3)
        {
            for(int i = 0; i<10; i+=2)
            {
                if(count[i]>0)
                {
                    ans.push_back(temp * 10 + i);
                }
            }
        }
    }
};