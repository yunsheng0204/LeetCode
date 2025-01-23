class Solution {
public:
    string countAndSay(int n) {
        string ans = "", previous = "";
        int count = 0;
        string temp = "", check = "";

        if(n == 1)
        {
            return "1";
        }
        else if(n == 2)
        {
            return "11";
        }
        else
        {
            previous = countAndSay(n-1);
            temp = previous[0];
            for(int i = 0; i <= previous.size(); i++)
            {
                if(i == previous.size())
                {
                    ans = ans + to_string(count) + temp;
                }
                else
                {
                    check = previous[i];
                    if(temp == check)
                    {
                        count++;
                    }
                    else
                    {
                        ans = ans + to_string(count) + temp;
                        temp = check;
                        count = 1;
                    }
                }
            }
            return ans;
        }
    }
};