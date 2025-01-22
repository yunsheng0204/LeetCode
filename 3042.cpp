class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int len = words.size();
        string temp = "";
        int count = 0;
        int str1_len = 0;
        int str2_len = 0;
        

        for(int i = 0; i<len; i++)
        {
            for(int j = i+1; j<len; j++)
            {
                str1_len = words[i].size();
                str2_len = words[j].size();
                if(str1_len > str2_len)
                {
                    continue;
                }
                for(int k = 0; k < str1_len; k++)
                {
                    if(words[i][k] != words[j][k] || words[i][k] != words[j][str2_len - str1_len + k])
                    {
                        break;
                    }
                    else if(k == str1_len-1)
                    {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};