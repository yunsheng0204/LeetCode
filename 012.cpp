class Solution {
public:
    string intToRoman(int num) {
        int len = log10(num) + 1;
        int n[4] = {0};
        string ans = "";
        for(int i = 0 ; i<len; i++)
        {
            n[i] = num % 10;
            num = num / 10;
            cout<<i<<" "<<n[i]<<endl;
        }
        for(int i = len - 1; i>=0; i--)
        {
            switch (i)
            {
                case 3:
                    for(int j = 0; j<n[i]; j++)
                    {
                        ans.append("M");
                    }
                    break;
                case 2:
                    switch(n[i])
                    {
                        case 9:
                            ans.append("CM");
                            break;
                        case 8: case 7: case 6: case 5:
                            ans.append("D");
                            for(int j = 0; j<n[i] - 5; j++)
                            {
                                ans.append("C");
                            }
                            break;
                        case 4:
                            ans.append("CD");
                            break;
                        case 3: case 2: case 1: case 0:
                            for(int j = 0; j<n[i]; j++)
                            {
                                ans.append("C");
                            }
                            break;
                    }
                    break;
                case 1:
                    switch(n[i])
                    {
                        case 9:
                            ans.append("XC");
                            break;
                        case 8: case 7: case 6: case 5:
                            ans.append("L");
                            for(int j = 0; j<n[i] - 5; j++)
                            {
                                ans.append("X");
                            }
                            break;
                        case 4:
                            ans.append("XL");
                            break;
                        case 3: case 2: case 1: case 0:
                            for(int j = 0; j<n[i]; j++)
                            {
                                ans.append("X");
                            }
                            break;
                    }
                    break;
                case 0:
                    switch(n[i])
                    {
                        case 9:
                            ans.append("IX");
                            break;
                        case 8: case 7: case 6: case 5:
                            ans.append("V");
                            for(int j = 0; j<n[i] - 5; j++)
                            {
                                ans.append("I");
                            }
                            break;
                        case 4:
                            ans.append("IV");
                            break;
                        case 3: case 2: case 1: case 0:
                            for(int j = 0; j<n[i]; j++)
                            {
                                ans.append("I");
                            }
                            break;
                    }
                    break;
            }
        }
        return ans;
    }
};