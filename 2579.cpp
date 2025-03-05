class Solution {
    public:
        long long coloredCells(int n) {
            long long int ans;
            if(n == 1)
            {
                return 1;
            }
            else
            {
                return coloredCells(n-1) + 4 *(n-1);
            }
        }
    };