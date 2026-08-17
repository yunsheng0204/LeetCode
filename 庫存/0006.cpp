class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
        {
            return s;
        }
        string ans = "";
        int d = 1;
        int i = 0;
        int n = 0;
        
        int len = s.size();
        vector<string> temp (numRows, "");

        while(i<len)
        {
            cout<<s[i]<<" 放 "<<n<<endl;
            temp[n] += s[i++];
            if(d == 1)
            {
                if(++n == numRows)
                {
                    d = -1;
                    n = numRows - 2;
                }
            }
            else if(d == -1)
            {
                if(--n < 0)
                {
                    d = 1;
                    n = 1;
                }
            }
        }

        i=0;
        while(i<numRows)
        {
            ans += temp[i];
            i++;
        }

        return ans;
    }
};