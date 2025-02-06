class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<long long int, int> mapp;

        int len = nums.size();
        long long int mult;
        int ans = 0;

        for(int i = 0; i<len; i++)
        {
            for(int j = i+1; j<len; j++)
            {
                mult = nums[i] * nums[j];
                mapp[mult]++;
            }
        }


        for (auto& [product, freq] : mapp)
        {
            if( freq > 1)
            {
                ans += (freq * (freq - 1) / 2) * 8;
            }
        }
        return ans;
    }
};