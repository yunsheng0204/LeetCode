class Solution {
public:
    int reverseDegree(string s) {
        int len = s.size();
        int ans = 0;

        for(int i = 0; i<len; i++)
        {
            // cout<<(26 - ((int)(s[i] - 'a')))<<" ";
            ans += (i + 1) * (26 - (s[i] - 'a'));
        }
        return ans;
    }
};
