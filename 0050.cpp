class Solution {
public:
    double myPow(double x, int n) { 
        double ans = 0;
        bool neg = 0;
        long time = abs(n);
        long i = 0;
        if(x == 1)
        {
            return 1;
        }
        else if(x == -1)
        {
            if(n%2 == 1)
            {
                return -1;
            }
            else
            {
                return 1;
            }
        }
        if(n<0)
        {
            neg = 1;
        }
        else if(n == 0)
        {
            return 1;
        }
        while(i < time)
        {
            if(i == 0)
            {
                ans = x;
                i++;
            }
            else if(2*i < time)
            {
                ans = ans * ans;
                i = i * 2;
            }
            else
            {
                ans = ans * x;
                i++;
            }
            
        }
        if(neg == 0)
        {
            return ans;
        }
        else
        {
            ans = 1.0/ans;
            return ans;
        }
    }
};