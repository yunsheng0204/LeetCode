class Solution {
    public:
        int numberOfSubstrings(string s) {
            long long int len = s.size();
            long long int ans = 0;
    
            vector<long long int> a;
            vector<long long int> b;
            vector<long long int> c;
    
            long long int i1 = 0;
            long long int i2 = 0;
            long long int i3 = 0;
    
            long long int last = 0;
    
            for(long long int i = 0; i<len; i++)
            {
                switch(s[i])
                {
                    case 'a':
                        a.push_back(i);
                        break;
                    case 'b':
                        b.push_back(i);
                        break;
                    case 'c':
                        c.push_back(i);
                        break;
                }
            }
            a.push_back(-1);
            b.push_back(-1);
            c.push_back(-1);
            for(long long int i = 0; i<len; i++)
            {
                if(a[i1] < i && a[i1] != -1)
                {
                    i1++;
                }
                if(b[i2] < i && b[i2] != -1)
                {
                    i2++;
                }
                if(c[i3] < i && c[i3] != -1)
                {
                    i3++;
                }
    
                if(a[i1] == -1 || b[i2] == -1 || c[i3] == -1)
                {
                    break;
                }
                else
                {
                    last = max(a[i1], b[i2]);
                    last = max(last, c[i3]);
                    ans += (len-last);
                }
            }
            return ans;
        }
    };