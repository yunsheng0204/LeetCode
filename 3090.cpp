class Solution {
public:
    int maximumLengthSubstring(string s) {
        int len = s.size();
        int begin = 0;
        vector<int> count (26, 0);
        int ans = 0;

        for(int i = 0; i<len; i++)
        {
            if(++count[s[i] - 'a'] == 3)
            {
                ans = max(ans, i-begin);
            }
            while(count[s[i] - 'a'] >= 3)
            {
                count[s[begin++] - 'a']--;
            }
        }

        return ans = max(ans, len-begin);
    }
};