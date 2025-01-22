class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        char a = ' ';
        int max = 0;
        int pos = 0;


        for(int i = 0;i<strs.size();i++)
        {
            if(strs[i].size()>max)
            {
                max = strs[i].size();
            }
        }
        for(int i = 0; i<max; i++)
        {
            a = strs[0][i];
            for(int j = 1; j<strs.size(); j++)
            {
                if(strs[j][i] != a)
                {
                    return ans;
                }
            }
            ans = ans + a;
        }
        return ans; 
    }
};