class Solution {
public:
    string getHint(string secret, string guess) {
        int len = guess.size();
        int temp_s[10];
        int temp_g[10];

        int countA = 0;
        int countB = 0;

        string ans = "";

        for(int i = 0; i<len; i++)
        {
            if(secret[i] == guess[i])
            {
                countA++;
            }
            else
            {
                temp_s[secret[i]-'0']++;
                temp_g[guess[i]-'0']++;
            }
        }
        for(int i = 0; i<10; i++)
        {
            countB = countB + min(temp_s[i], temp_g[i]);
        }

        ans = to_string(countA) + "A" + to_string(countB) + "B";

        return ans;
    }
};