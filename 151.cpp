class Solution {
public:
    string reverseWords(string s) {
        string temp = "";
        string ans = "";
        for(int i = s.size()-1; i>=0; i--)
        {
            temp = "";
            while(s[i] != ' ')
            {
                temp = s[i] + temp;
                i--;
                if(i<0)
                {
                    break;
                }
            }
            if(temp != "")
            {
                ans = ans + temp + " ";
            }
        }
        ans = ans.substr(0, ans.size() - 1);
        return ans;
    }
};