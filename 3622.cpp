class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int pro = 1;
        int num = n;

        while(num >= 1)
        {
            sum += num % 10;
            pro *= num % 10;
            num = num / 10;
        }

        if(n % ( sum + pro ) == 0)
        {
            return true;
        }
        return false;
    }
};