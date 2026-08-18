class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        int c = len / 2;
        int j;
        char temp;

        for(int i = 0; i<c; i++)
        {
            j = len-i-1;

            temp = s[j];
            s[j] = s[i];
            s[i] = temp;
        }
        
    }
};