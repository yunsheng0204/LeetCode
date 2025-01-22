class Solution {
public:
    int hammingWeight(int n) {
        int sum = 0;
        while(n>1)
        {
            if(n%2 == 1)
            {
                sum ++;
            }
            n = n / 2;
        }
        if( n == 1 )
        {
            sum++;
        }
        return sum;
    }
};