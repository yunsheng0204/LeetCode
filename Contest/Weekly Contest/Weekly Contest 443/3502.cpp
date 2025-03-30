class Solution {
    public:
        vector<int> minCosts(vector<int>& cost) {
            int len = cost.size();
            vector<int> ans;
            int mini = 101;
    
            for(int i = 0; i<len; i++)
            {
                mini = min(mini, cost[i]);
                ans.push_back(mini);
            }
            return ans;
        }
    };