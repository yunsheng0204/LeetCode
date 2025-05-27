class Solution {
public:
    int differenceOfSums(int n, int m) {
        int ans = 0;
        int num1 = n * (n + 1) / 2;
        int t = n / m;
        double num2 = (m + (m*t));
        num2 /= 2;
        num2 *= t;

        return num1 - 2*num2;
    }
};