class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int len = words.size();
        vector<string> ans;
        vector<int> word_len(len);
        vector<int> pre_index(len, -1);
        vector<int> same_len(len, 1);
        int maxi = 0;
        int max_index = 0;
        int cur;

        for(int i = 0; i<len; i++)
        {
            word_len[i] = words[i].size();
        }

        for(int i = 1; i<len; i++)
        {
            for(int j = i - 1; j>=0; j--)
            {
                if(groups[i] != groups[j])
                {
                    if(word_len[i] == word_len[j])
                    {
                        if(ham(words[i], words[j], word_len[i]) == true)
                        {
                            if(same_len[j] + 1 > same_len[i])
                            {
                                same_len[i] = same_len[j] + 1;
                                pre_index[i] = j;
                            }
                        }
                    }
                }
            }
        }

        for(int i = 0; i < len; i++)
        {
            if(same_len[i] >same_len[max_index])
            {
                max_index = i;
            }
        }

        cur = max_index;

        while(cur != -1)
        {
            ans.push_back(words[cur]);
            cur = pre_index[cur];
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

    bool ham(string s1, string s2, int len)
    {
        int diff = 0;
        for(int i = 0; i<len; i++)
        {
            if(s1[i] != s2[i])
            {
                if(++diff == 2)
                {
                    return false;
                }
            }
        }

        if(diff == 1)
        {
            return true;
        }
        return false;
    }
};