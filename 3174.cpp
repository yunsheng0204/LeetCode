class Solution {
public:
    string clearDigits(string s) {
        int len = s.size();

        for(int i = 0; i<len; i++)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                s.erase(i-1, 2);
                i = i-2;
                len = len - 2;
            }
        }
        return s;
    }
};