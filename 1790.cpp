class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int count = 0;
        int len = s1.size();
        vector<char> check1;
        vector<char> check2;

        if(s1 == s2)
        {
            return true;
        }

        for(int i = 0; i<len; i++)
        {
            if(s1[i] != s2[i])
            {
                if(++count > 2)
                {
                    return false;
                }
                check1.push_back(s1[i]);
                check2.push_back(s2[i]);
            }
        }
        if(count == 1)
        {
            return false;
        }
        else if(check1[0] == check2[1] && check1[1] == check2[0])
        {
            return true;
        }
        return false;
    }
};