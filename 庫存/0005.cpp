class Solution {
public:
    void check(string &ans, float index, int &len, string &s, bool &inte, int &maxi)
    {
        int j = 1;
        if(inte == true)
        {
            while(index-j >= 0 && index+j<len)
            {
                if(s[index-j] == s[index+j])
                {
                    if(2*j + 1 > maxi)
                    {
                        maxi = 2*j + 1;
                        ans = s.substr(index-j, maxi);
                    }
                    j++;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            while(index-j+0.5 >= 0 && index+j<len)
            {
                if(s[index-j+0.5] == s[index+j])
                {
                    if(2*j > maxi)
                    {
                        maxi = 2*j;
                        ans = s.substr(index-j+0.5, maxi);
                    }
                    j++;
                }
                else
                {
                    break;
                }
            }
        }
        
    }

    string longestPalindrome(string s) {
        string ans = s.substr(0, 1);
        int len = s.size();
        bool inte = true;
        int maxi = 1;

        for(float i = 0; i<len; i +=0.5)
        {
            check(ans, i, len, s, inte, maxi);
            inte = !inte;
        }
        return ans;
    }
};