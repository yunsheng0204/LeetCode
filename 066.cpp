class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        int c = 0;

        digits[len-1]++;

        if(digits[len-1]>9)
        {
            digits[len-1] = 0;
            c = 1;
        }

        for(int i = len-2;i>=0; i--)
        {
            cout<<i<<" ";
            if(c==1)
            {
                digits[i]++;
                if(digits[i]>9)
                {
                    digits[i] = 0;
                    c = 1;
                }
                else
                {
                    c = 0;
                }
            } 
            else
            {
                break;
            }
        }
        if(c == 1)
        {
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};