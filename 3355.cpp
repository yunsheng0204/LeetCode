class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int len = queries.size();
        int len_nums = nums.size();

        vector<int> prefix(len_nums + 1, 0);
        vector<int> pre(len_nums + 1, 0);

        for(int i = 0 ;i<len; i++)
        {
            pre[queries[i][0]]++;
            pre[queries[i][1] + 1]--;
        }
        prefix[0] = pre[0];
        for(int i = 0; i<len_nums; i++)
        {
            prefix[i+1] = pre[i+1] + prefix[i];
        }

        for(int i = 0; i<len_nums; i++)
        {
            if(nums[i] - prefix[i] > 0)
            {
                return false;
            }
        }

        return true;
    }
};