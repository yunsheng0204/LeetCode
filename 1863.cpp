class Solution {
    public:
        int subsetXORSum(vector<int>& nums) {
            int len = nums.size();
            int len_temp;
            int len_temp2;
            int index = 0;
            int ans = 0;
            int ans_temp = 0;
            vector<vector<int>> subset;
            vector<int> temp(0,0);
            subset.push_back(temp);
    
            for(int i = 0; i<len; i++)
            {
                get_subset(subset, nums, i);
            }
    
            len_temp = subset.size();
            for(int i = 0; i<len_temp; i++)
            {
                ans_temp = 0;
                temp = subset[i];
                len_temp2 = temp.size();
                for(int j = 0; j<len_temp2; j++)
                {
                    // cout<<temp[j]<<" ";
                    ans_temp = ans_temp ^ temp[j];
                }
                ans += ans_temp;
            }
            return ans;
        }
        void get_subset(vector<vector<int>> &subset, vector<int>& nums, int index)
        {
            int len_temp = subset.size();
            vector<int> temp;
            for(int i = 0; i<len_temp; i++)
            {
                temp = subset[i];
                temp.push_back(nums[index]);
                subset.push_back(temp);
            }
        }
    };