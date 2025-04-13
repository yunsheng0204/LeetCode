class Solution {
public:
    int findClosest(int x, int y, int z) {
        int x1 = abs(x-z);
        int x2 = abs(y-z);

        if(x1 == x2)
        {
            return 0;
        }
        else if(x1<x2)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
};
