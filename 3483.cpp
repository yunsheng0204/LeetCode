class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int len = digits.size();
        vector<int> count(10,0);
        int ans = 0;
        for(int i = 0; i<len; i++)
        {
            count[ digits[i] ]++;
        }
        
        return count_(count, 3, ans);
    }
    
    int count_(vector<int>& count, int layer, int ans)
    {
        int temp2 = 0;
        if(layer == 1)
        {
            for(int i = 1; i<10; i++)
            {
                if(count[i]>0)
                {  
                    count[i] --;
                    temp2 += count_(count, 2, ans);
                    count[i] ++;
                }
            }
            return temp2;
        }
        else if(layer == 2)
        {
            for(int i = 0; i<10; i++)
            {
                if(count[i]>0)
                {  
                    temp2++;
                }
            }
            return temp2;
        }
        else
        {
            int count_evan = 0;
            if(count[0] > 0)
            {
                count[0] --;
                ans += count_(count, 1, ans);
                count[0] ++;
            }
            if(count[2] > 0)
            {
                count[2]--;
                ans += count_(count, 1, ans);
                count[2]++;
            }
            if(count[4] > 0)
            {
                count[4]--;
                ans += count_(count, 1, ans);
                count[4]++;
            }
            if(count[6] > 0)
            {
                count[6]--;
                ans += count_(count, 1, ans);
                count[6]++;
            }
            if(count[8] > 0)
            {
                count[8]--;
                ans += count_(count, 1, ans);
                count[8]++;
            }
            return ans;
        }
    }
};