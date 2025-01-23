class Solution {
public:
    bool isPalindrome(int x) {

        if(x == 0)
        {
            return 1;
        }
        else
        {
            int left = 0, right = 0;
            if(x<0)
            {
                return 0;
            }
            int leng = floor(log10(x)) + 1;

            while(x != 0)
            {
                if(x < 10)
                {
                    if(leng == 1)
                    {
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                }
                else
                {
                    left = x / pow(10,--leng);
                    right = x % 10;
                    if(left != right)
                    {
                        return 0;
                    }

                    x = x / 10;
                    x = x % int(pow(10,--leng));
                }
            }
            return 1;
        }
    }
};