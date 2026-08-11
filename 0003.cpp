class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        vector<int> last(128, -1);
        int ans = 0;
        int temp = 0;
        int begin = 0;

        for(int i = 0; i<len; i++)
        {
            if(last[s[i]] == -1)
            {
                last[s[i]] = i;
                ans = max(ans, i-begin + 1);
            }
            else if(i>last[s[i]])
            {
                ans = max(ans, i-begin);
                if(last[s[i]] + 1 >= begin)
                {
                    begin = last[s[i]] + 1;
                }
                last[s[i]] = i;
                i = begin - 1;
            }
        }
        return max(ans, len-begin);
    }
};