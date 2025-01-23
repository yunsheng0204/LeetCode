class Solution {
public:
    int reverse(int x) {
        bool neg = 0;
        long ans = 0;
        long temp = x;
        if(x < 0)
        {
            neg = 1;
            temp = -temp;
        }
        if(temp == 0)
        {
            return ans;
        }
        int leng = floor(log10(temp) + 1);
        if(leng>10)
        {
            return ans;
        }

        int *num = new int [leng];
        for(int i = 0 ; i<leng; i++)
        {
            num[i] = temp % 10;
            temp = temp/10;
        }
        for(int i = 0;i<leng;i++)
        {
            ans = 10 * ans + num[i];
            if(leng == 10)
            {
                if(ans > 2147483648)
                {
                    return 0;
                }
            }
        }
        if(neg == 1)
        {
            return -ans;
        }
        return ans;
    }
};