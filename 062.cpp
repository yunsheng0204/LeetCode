class Solution {
public:
    int uniquePaths(int m, int n) {
        m--;
        n--;
        int  sum = m + n;
        int min;
        int count = 1;
        

        long long int ans = 1;

        if(m<n)
        {
            min = m;
        }
        else
        {
            min = n;
        }

        bool *check = new bool [min+1];
        for(int i = 1; i<=min; i++)
        {
            check[i] = 0;
        }

        for(int i = 1; i<=min; i++)
        {
            ans = ans * sum;
            for(int j = 1; j<=min; j++)
            {
                if(check[j] == 0 && ans % j == 0)
                {
                    ans = ans / j;
                    check[j] = 1;
                }
            }
            sum--;
        }
        for(int j = 1; j<=min; j++)
        {
            if(check[j] == 0)
            {
                ans = ans / j;
                check[j] = 1;
            }
        }
        return ans;
    }
};