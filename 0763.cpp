class Solution {
    public:
        vector<int> partitionLabels(string s) {
            int len = s.size();
            int index = 0;
            int count = 0;
            int temp = 0;
            vector<int> ans;
            vector<int> end_(26, 0);
    
            for(int i = 0; i<len; i++)
            {
                end_[s[i] - 'a'] = i;
            }
            for(int i = 0; i<len; i++)
            {
                count++;
                temp = max(end_[s[i] - 'a'], temp);
                if(temp == i)
                {
                    ans.push_back(count);
                    count = 0;
                    temp = 0;
                }
            }
            return ans;
        }
    };