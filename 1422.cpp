class Solution {
public:
    int maxScore(string s) {
        int len = s.size();

        int left = 0;
        int right = 0;

        int ans = 0;
        
        for(int i = 0; i<len; i++)
        {
            if(s[i] == '1')
            {
                right++;
            }
        }

        for(int i = 0; i<len-1; i++)
        {
            if(s[i] == '0')
            {
                left++;
            }
            else
            {
                right--;
            }
            ans = max(ans, left + right);
        }
        return ans;
    }
};