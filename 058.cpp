class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        while(s.length()!=0)
        {
            if(s.back()==' ')
            {
                s.pop_back();
            }
            else
            {
                break;
            }
        }
        while(s.length()!=0)
        {
            if(s.back()!=' ')
            {
                ans++;
                s.pop_back();
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};