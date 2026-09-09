class Solution {
public:
    void function(string &digits, int l, vector<string> &ans, string s)
    {
        if(l == digits.size())
        {
            ans.push_back(s);
        }
        else
        {
            switch(digits[l])
            {
                case '2':
                    function(digits, l+1 , ans, s + "a");
                    function(digits, l+1 , ans, s + "b");
                    function(digits, l+1 , ans, s + "c");
                    break;
                case '3':
                    function(digits, l+1 , ans, s + "d");
                    function(digits, l+1 , ans, s + "e");
                    function(digits, l+1 , ans, s + "f");
                    break;
                case '4':
                    function(digits, l+1 , ans, s + "g");
                    function(digits, l+1 , ans, s + "h");
                    function(digits, l+1 , ans, s + "i");
                    break;
                case '5':
                    function(digits, l+1 , ans, s + "j");
                    function(digits, l+1 , ans, s + "k");
                    function(digits, l+1 , ans, s + "l");
                    break;
                case '6':
                    function(digits, l+1 , ans, s + "m");
                    function(digits, l+1 , ans, s + "n");
                    function(digits, l+1 , ans, s + "o");
                    break;
                case '7':
                    function(digits, l+1 , ans, s + "p");
                    function(digits, l+1 , ans, s + "q");
                    function(digits, l+1 , ans, s + "r");
                    function(digits, l+1 , ans, s + "s");
                    break;
                case '8':
                    function(digits, l+1 , ans, s + "t");
                    function(digits, l+1 , ans, s + "u");
                    function(digits, l+1 , ans, s + "v");
                    break;
                case '9':
                    function(digits, l+1 , ans, s + "w");
                    function(digits, l+1 , ans, s + "x");
                    function(digits, l+1 , ans, s + "y");
                    function(digits, l+1 , ans, s + "z");
                    break;
            }
        }
    }

    vector<string> letterCombinations(string digits) {

        int len = digits.size();

        for(int i = 0; i<digits.size(); i++)
        {
            if(digits[i] == '7' | digits[i] == '9')
            {
                len *= 4;
            }
            else
            {
                len *= 3;
            }
        }

        vector<string> ans;

        function(digits, 0, ans, "");


        return ans;
        
    }

    
};