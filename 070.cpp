class Solution {
public:
    int record [46] = {0};
    int climbStairs(int n) {

        if(record[n]!=0)
        {
            return record[n];
        }

        int sum = 0;
        if(n == 1)
        {
            record[1] = 1;
            return 1;
        }
        else if(n == 2)
        {
            record[2] = 2;
            return 2;
        }
        else
        {
            
            int  temp = 0;
            for(int i = 1, j = n-i; i<n; i++,j--)
            {
                sum = climbStairs(n-2) + climbStairs(n-1);
            }
            record[n] = sum;
            return sum;
        }
    }
};