class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int max = prices[0];

        int len = prices.size();

        int ans = 0;

        for(int i = 0; i<len; i++)
        {
            if(prices[i]<min)
            {
                min = prices[i];
                max = prices[i];
            }
            else if(prices[i]>max)
            {
                max = prices[i];
                if(max-min>ans)
                {
                    ans = max-min;
                }
            }
        }
        return ans;
    }
};