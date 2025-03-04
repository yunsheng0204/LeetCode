class Solution {
    public:
        bool checkPowersOfThree(int n) {
            while(n >= 1)
            {
                if(n%3 == 2)
                {
                    return false;
                }
                else
                {
                    n /= 3;
                }
            }
            return true;
        }
    };