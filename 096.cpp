class Solution {
public:
    int temp[20] = {0};
    int t;
    
    int numTrees(int n) {
        if (n == 1 || n == 0)
        {
            temp[0] = 1;
            temp[1] = 1;
            return 1;
        }
        else
        {
            if(temp[n]!=0)
            {
                return temp[n];
            }
            else
            {
                int sum = 0;
                for(int i = 0; i<n; i++)
                {
                    t = n-i-1;
                    sum = sum + numTrees(i)*numTrees(t);
                }
                temp[n] = sum;
                cout<<n<<" "<<sum<<endl;
                return sum;
            }
        }
    }
};