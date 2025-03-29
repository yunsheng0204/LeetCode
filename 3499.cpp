class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {

        s = "1" + s + "1";
        int len  = s.size();
        char now = s[0];
        int count = 1;
        vector<vector<int>> q;
        vector<vector<int>> q_temp;
        int ans = 0;
        int ans_temp = 0;
        int change = 0;
        int change_temp = 0;
        int one_count = 0;

        for(int i = 0; i<len; i++)
        {
            if(s[i] == '1')
            {
                one_count++;
            }
        }
        one_count = one_count - 2;

        for(int i = 1; i<len; i++)
        {
            if(s[i] == now)
            {
                count++;
            }
            else
            {
                q.push_back({now - '0',count});
                // cout<<now - '0'<<" "<<count<<endl;
                count = 1;
                if(now == '0')
                {
                    now = '1';
                }
                else
                {
                    now = '0';
                }
            }
        }
        q.push_back({now - '0',count});
        
        // cout<<now - '0'<<" "<<count<<endl;

        int len_temp = q.size();
        if(len_temp == 1 && q[0][0] == 1)
        {
            return q[0][1] - 2;
        }
        else if(len_temp == 2)
        {
            if(q[0][0] == 1)
            {
                return q[0][1] - 1;
            }
            else
            {
                return q[1][1] - 1;
            }
        }
        else if(len_temp == 3 && q[0][0] == 1)
        {
            if(q[0][1] == 1 && q[2][1] == 1)
            {
                return 0;
            }
            else if(q[0][1] == 1 || q[2][1] == 1)
            {
                return max(q[0][1]-1, q[2][1] - 1);
            }
            return q[0][1] + q[2][1] - 2;
        }
        else
        {
            for(int i = 1; i<len_temp-1; i++)
            {
                if(q[i][0] == 1 && q[i+1][0] == 0)
                {
                    // ans_temp = q[i - 2][1] + q[i - 1][1] + q[i][1] + q[i + 1][1] + q[i + 2][1];
                    change_temp = q[i - 1][1] + q[i + 1][1];
                    // if(i-2 == 0)
                    // {
                    //     ans_temp--;
                    // }
                    // if(i+2 == len_temp - 1)
                    // {
                    //     ans_temp--;
                    // }
                    change = max(change, change_temp);
                }
            }
        }
        return change + one_count;
    }
};
