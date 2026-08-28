class Solution {
public:
    bool canGreater(string left, vector<int>& count, char middle, string& target)
    {
        string maxLeft = left;

        for(int i = 25; i >= 0; i--)
        {
            for(int j = 0; j < count[i]; j++)
            {
                maxLeft += ('a' + i);
            }
        }

        string right = maxLeft;
        reverse(right.begin(), right.end());

        string palindrome = maxLeft;

        if(middle != ' ')
        {
            palindrome += middle;
        }

        palindrome += right;

        return palindrome > target;
    }

    string lexPalindromicPermutation(string s, string target) {
        int len = s.size();
        vector<int> count(26, 0);
        int half = len / 2;
        int odd = 0;
        char middle = ' ';
        string left = "", right = "", ans = "";

        for(int i = 0; i < len; i++)
        {
            count[s[i] - 'a']++;
        }

        for(int i = 0; i < 26; i++)
        {
            if(count[i] % 2 == 1)
            {
                odd++;
                middle = 'a' + i;
            }
        }

        if(len % 2 == 0 && odd != 0)
        {
            return "";
        }
        else if(len % 2 == 1 && odd != 1)
        {
            return "";
        }


        for(int i = 0; i < 26; i++)
        {
            count[i] /= 2;
        }


        for(int pos = 0; pos < half; pos++)
        {
            bool found = false;


            for(int c = 0; c < 26; c++)
            {
                if(count[c] == 0)
                {
                    continue;
                }
                count[c]--;
                left += (c + 'a');

                if(canGreater(left, count, middle, target))
                {
                    found = true;
                    break;
                }

                left.pop_back();
                count[c]++;
            }


            if(found == false)
            {
                return "";
            }
        }



        right = left;
        reverse(right.begin(), right.end());

        ans = left;

        if(middle != ' ')
        {
            ans += middle;
        }
        ans += right;

        if(ans <= target)
        {
            return "";
        }

        return ans;
    }
};