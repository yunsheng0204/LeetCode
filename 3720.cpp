class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int len = s.size();
        vector<int> count(26, 0);
        string ans = "";
        int index = 0;
        bool k = false;
        char a;

        for(int i = 0; i<len; i++)
        {
            count[s[i]-'a']++;
        }
        len = target.size();

        for(int i = 0; i<len; i++)
        {
            if(k == true)
            {
                index = 0;
                while(count[index] == 0)
                {
                    index++;
                }
                a = index + 'a';
                count[index]--;
                ans += a;
            }
            else
            {
                
                if(count[target[i] - 'a'] > 0 && i != len - 1)
                {
                    index = target[i] - 'a';
                    a = index + 'a';
                    count[index]--;
                    ans += a;
                }
                else
                {
                    flag:
                    index = target[i] - 'a' + 1;
                    if(index == 26)
                    {
                        if(i == 0)
                        {
                            return "";
                        }
                        i--;
                        index = target[i] - 'a';
                        count[index]++;
                        ans.pop_back();
                        goto flag;
                    }
                    while(count[index] == 0)
                    {
                        index = (index + 1);
                        if(index == 26)
                        {
                            if(i == 0)
                            {
                                return "";
                            }
                            i--;
                            index = target[i] - 'a';
                            count[index]++;
                            ans.pop_back();
                            goto flag;
                        }
                    }
                    a = index + 'a';
                    count[index]--;
                    ans += a;
                    k = true;
                }
            }
        }
        return ans;
    }
};