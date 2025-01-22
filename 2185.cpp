class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int len = words.size();

        int len_check = pref.size();

        int count = 0;

        for(int i = 0; i<len; i++)
        {
            count++;
            for(int j = 0; j<len_check; j++)
            {
                if(words[i][j] != pref[j])
                {
                    count--;
                    break;
                }
            }
        }

        return count;
    }
};