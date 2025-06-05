class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int len = s1.size();
        int len_baseStr = baseStr.size();
        int t = 0;
        int temp = 0;
        char te = ' ';
        string ans = "";

        vector<int> group(26, 0);

        for(int i = 0; i<26; i++)
        {
            group[i] = i;
        }

        for(int i = 0; i<len; i++)
        {
            
            if(group[s1[i] - 'a'] < group[s2[i] - 'a'])
            {
                t = group[s1[i] - 'a'];
                temp = group[s2[i] - 'a'];
            }
            else
            {
                t = group[s2[i] - 'a'];
                temp = group[s1[i] - 'a'];
            }
            for(int j = 0; j<26; j++)
            {
                if(group[j] == temp)
                {
                    group[j] =  t;
                }
            }
        }


        for(int i = 0; i<len_baseStr; i++)
        {
            ans += (char)(group[baseStr[i] - 'a'] + 'a');
        }

        return ans;
    }
};