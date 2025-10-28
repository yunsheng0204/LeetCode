class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int len = nums.size();
        int sum = 0, sum1 = 0;
        int ans = 0;
        vector<int> z;
        vector<int> pre(len, 0);
        vector<int> post(len, 0);

        for(int i = 0; i<len; i++)
        {
            sum += nums[i];
            sum1 += nums[len-1-i];
            pre[i] = sum;
            post[len-1-i] = sum1;
            if(nums[i] == 0)
            {
                z.push_back(i);
            }
        }
        len = z.size();

        for(int i = 0; i<len; i++)
        {
            if(pre[z[i]] == post[z[i]])
            {
                ans += 2;
            }
            else if (abs(pre[z[i]]-post[z[i]]) == 1)
            {
                ans += 1;
            }
        }

        return ans;
    }
};