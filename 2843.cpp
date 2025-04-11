class Solution {
    public:
        int countSymmetricIntegers(int low, int high) {
            int ans = 0;
            int len = 0;
            int len2 = 0;
            int c1, c2;
            string temp = "";
    
            for(int i = low; i<=high; i++)
            {
                temp = to_string(i);
                len = temp.size();
                len2 = len / 2;
                if(len % 2 == 0)
                {
                    c1 = 0;
                    c2 = 0;
                    for(int j = 0; j<len2; j++)
                    {
                        c1 += temp[j] - '0';
                        c2 += temp[len-1-j] - '0';
                    }
                    if(c1 == c2)
                    {
                        // cout<<temp<<" "<<c1<<" "<<c2<<endl;
                        ans++;
                    }
                }
            }
            return ans;
        }
    };