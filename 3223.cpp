class Solution {
public:
    int minimumLength(string s) {
        int len = s.size();
        int ans = 0;
        int count [26];
        char temp;

        for(int i = 0; i<len; i++)
        {
            temp = s[i];
            count[ temp-'a' ]++;
        }
        for(int i = 0; i<26; i++)
        {
            if(count[i]>2)
            {
                count[i] = (count[i]+1)%2 + 1;
            }
            ans = ans + count[i];
        }

        return ans;
    }
};