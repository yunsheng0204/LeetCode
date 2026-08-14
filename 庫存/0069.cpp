class Solution {
public:
    int mySqrt(int x) {

        long long ans = 1;

        while(x >= ans * ans)
        {
            ans++;
        }
        return ans-1;
    }
};