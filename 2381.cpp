class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int len = s.size();

        int times = shifts.size();
        vector<int> shif(len+1,0);

        for(int i = 0; i<times; i++)
        {
            if(shifts[i][2] == 0)
            {
                shif[shifts[i][0]]--;
                shif[shifts[i][1]+1]++;
            }
            else
            {
                shif[shifts[i][0]]++;
                shif[shifts[i][1]+1]--;
            }
        }
        for(int i = 1; i<len;i++)
        {
            shif[i] = shif[i-1] + shif[i];
        }
        for(int i = 0; i<len;i++)
        {
            shif[i] = shif[i] % 26;
        }
        for(int i = 0; i<len; i++)
        {
            if( s[i] + shif[i]>'z')
            {
                shif[i] = shif[i] - 26;
            }
            else if( s[i] + shif[i]<'a')
            {
                shif[i] = shif[i] + 26;
            }
        }
        for(int i = 0; i<len; i++)
        {
            s[i] = s[i] + shif[i];
        }
        return s;
    }
};