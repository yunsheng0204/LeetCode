class Solution {
public:
    int myAtoi(string s) {
        char *word = new char[s.length() + 1];
        bool neg = 0;
        int pos = 0;
        int ascii = 0;
        long long int sum = 0;
        long int min = -2147483648;
        long int max = 2147483647;
        bool start = 0;
        strcpy(word, s.c_str());
        // cout<<s.length();
        // cout<<word[s.length()];
        
        while( pos!=s.length() )
        {
            ascii = word[pos];
            // cout<<ascii<<endl;

            if( ascii>57 || (ascii<48 && (ascii != 32)&&(ascii != 43)&&(ascii != 45)) ||  (((ascii == 32)||(ascii == 43)||(ascii == 45))&&(sum!=0))  )   //ascii(0-9) = 48-57
            {
                cout<<"break1"<<endl;
                break;
            }
            if( ascii == 32 )       // _
            {
                if(start == 1)
                {
                    break;
                }
                // cout<<"_"<<endl;
                pos++;
                continue;
            }
            else if( ascii == 43 )  // +
            {
                if(start == 1)
                {
                    break;
                }
                start = 1;
            }
            else if( ascii == 45 )  // -
            {
                if(start == 1)
                {
                    break;
                }
                neg = 1;
                start = 1;
            }
            else
            {
                start = 1;
                sum = 10*sum + (ascii - 48);
                // cout<<sum<<endl;
                if(sum>max)
                {
                    if(neg == 1)
                    {
                        return min;
                    }
                    return max;
                }
            }
            pos++;
        }
        if(neg == 1)
        {
            sum = -sum;
        }
        return sum;
    }
};