class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int len = s.size();
        int count[26] = {0};
        int count_temp[26] = {0};
        int first[26] = {0};
        int last[26] = {0};
        int ans = 0;

        vector<int> repeat(len, 0);
        int total_count = 0;

        for(int i = 0; i<len; i++)
        {
            if(++count[s[i]-'a'] == 1)
            {
                first[s[i]-'a'] = i;
                last[s[i]-'a'] = i;
            }
            else
            {
                last[s[i]-'a'] = i;
            }
        }

        for(int i = 0; i<26; i++)
        {
            if(count[i] >= 2)
            {

                if(last[i] - first[i] >= 2)
                {
                    for(int j = first[i] + 1; j < last[i]; j++)
                    {
                        if(++count_temp[s[j]-'a'] == 1)
                        {
                            ++total_count;
                        }
                    }
                    ans += total_count;
                }
            }
            for(int j = 0; j<26; j++)
            {
                count_temp[j] = 0;
            }
            total_count = 0;
        }
        return ans;
    }
};