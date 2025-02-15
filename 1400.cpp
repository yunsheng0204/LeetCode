class Solution {
public:
    bool canConstruct(string s, int k) {
        int count[26];
        int odd_count = 0;

        int len = s.size();

        if(k > len)
        {
            return false;
        }
        else if(k == len)
        {
            return true;
        }

        for(int i = 0; i<len; i++)
        {
            count[s[i]-'a']++;
        }

        for(int i = 0; i<26; i++)
        {
            if(count[i] % 2 == 1)
            {
                odd_count++;
            }
        }
        if(odd_count > k)
        {
            return false;
        }
        return true;

    }
};