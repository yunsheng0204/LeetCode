class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> maxi(len, 0);
        vector<int> mini(len, INT_MAX);
        maxi[0] = nums[0];
        mini[len-1] = nums[len-1];

        for(int i = 1; i<len; i++)
        {
            maxi[i] = max(maxi[i-1], nums[i]);
            mini[len-1-i] = min(mini[len-i], nums[len-1-i]);
        }

        for(int i = 0; i<len; i++)
        {
            if(maxi[i] - mini[i] <= k)
            {
                return i;
            }
        }

        return -1;
    }
};