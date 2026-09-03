class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int len = nums1.size();
        bool odd = false;
        bool even = false;

        if(len == 1)
        {
            return true;
        }

        int maxi_odd = -1;
        int maxi_even = -1;
        int mini_odd = INT_MAX;
        int mini_even = INT_MAX;

        for(int i = 0; i<len; i++)
        {
            if(nums1[i] % 2  == 0)
            {
                even = true;
                maxi_even = max(maxi_even, nums1[i]);
                mini_even = min(mini_even, nums1[i]);
            }
            else
            {
                odd = true;
                maxi_odd = max(maxi_odd, nums1[i]);
                mini_odd = min(mini_odd, nums1[i]);
            }
        }

        if((odd == true && even == false) || (odd == false && even == true))
        {
            return true;
        }
        else if(mini_even < mini_odd)
        {
            return false;
        }

        return true;

    }
};