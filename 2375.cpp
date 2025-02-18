class Solution {
    public:
        string smallestNumber(string pattern) {
            bool check = false;
            char last = 'I';
            string temp = "1";
            string ans = "";
            char count = '1';
    
            int len = pattern.size();
    
            for(int i = 0; i<len; i++)
            {
                count++;
                if(pattern[i] == 'D')
                {
                    temp += count;
                }
                else if(pattern[i] == 'I' && last =='D')
                {
                    reverse(temp.begin(), temp.end());
                    ans += temp;
                    temp = count;
                }
                else if(pattern[i] == 'I' && last =='I')
                {
                    ans += temp;
                    temp = count;
                }
                last = pattern[i];
            }
            if(last == 'D')
            {
                reverse(temp.begin(), temp.end());
                ans += temp;
            }
            else
            {
                ans += temp;
            }
            return ans;
        }
    };