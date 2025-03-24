class Solution {
    public:
        int countDays(int days, vector<vector<int>>& meetings) {
            int len = meetings.size();
            vector<int> *temp1, *temp2;
            int ans = 0;
            vector<vector<int>> meetings_temp;
    
            sort(meetings.begin(), meetings.end());
    
    
            for(int i = 1; i<len; i++)
            {
                temp1 = &meetings[i-1];
                temp2 = &meetings[i];
    
                if((*temp2)[0] <= (*temp1)[1])
                {
                    (*temp2)[0] = (*temp1)[0];
                    (*temp2)[1] = max((*temp1)[1], (*temp2)[1]);
                }
                else
                {
                    meetings_temp.push_back(*temp1);
                }
            }
            meetings_temp.push_back(meetings[len-1]);
    
            len = meetings_temp.size();
            for(int i = 1; i<len; i++)
            {
                temp1 = &meetings_temp[i-1];
                temp2 = &meetings_temp[i];
                
                if(((*temp2)[0] - (*temp1)[1] - 1) > 0)
                {
                    ans += (*temp2)[0] - (*temp1)[1] - 1;
                }
            }
            if(meetings_temp[len-1][1] < days)
            {
                ans += days - meetings_temp[len-1][1];
            }
            if(meetings_temp[0][0] > 1)
            {
                ans += meetings_temp[0][0] - 1;
            }
            return ans;
        }
    };