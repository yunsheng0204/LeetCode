class Solution {
public:
    int maxDiff(int num) {
        vector<int> n(9,0);
        vector<int> big_n(9,0);
        vector<int> small_n(9,0);
        int t = 100000000;
        int big_temp = -1, small_temp = -1, small_temp2 = -1;
        int big = 0;
        int small = 0;
        bool check = false;
        bool check2 = false;

        for(int i = 8; i>=0; i--)
        {
            n[i] = num / t;
            // cout<<n[i]<<" ";
            num %= t;
            t /= 10;
        }

        big_n = n;
        small_n = n;

        for(int i = 8; i>=0; i--)
        {
            if(big_temp == -1)
            {
                if(check == false && n[i] != 0)
                {
                    check = true;
                }
                if(n[i] != 9 && check == true)
                {
                    big_temp = n[i];
                    big_n[i] = 9;
                }
            }
            else
            {
                if(n[i] == big_temp)
                {
                    big_n[i] = 9;
                }
            }

            if(small_temp == -1)
            {
                if(check2 == false && n[i] == 1)
                {
                    small_temp2 = 0;
                }
                else if(check2 == false && n[i] != 0)
                {
                    check2 = true;
                    if(small_temp2 != 0)
                    {
                        small_temp2 = 1;
                    }
                }
                if(n[i] != 1 && check2 == true)
                {
                    small_temp = n[i];
                    small_n[i] = small_temp2;
                }
            }
            else
            {
                if(n[i] == small_temp)
                {
                    small_n[i] = small_temp2;
                }
            }
        }


        for(int i = 8; i>=0; i--)
        {
            big = 10 * big + big_n[i];
            small = 10 * small + small_n[i];
        }

        cout<<big<<" "<<small;

        return big - small;
    }
};