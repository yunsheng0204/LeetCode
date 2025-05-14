class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        bool lock1 = false, lock2 = false;
        long long sum1 = 0, sum2 = 0;

        for(int i = 0; i<len1; i++)
        {
            if(nums1[i] == 0)
            {
                sum1 += 1;
                lock1 = true;
            }
            else
            {
                sum1 += nums1[i];
            }
        }
        for(int i = 0; i<len2; i++)
        {
            if(nums2[i] == 0)
            {
                sum2 += 1;
                lock2 = true;
            }
            else
            {
                sum2 += nums2[i];
            }
        }

        if(lock1 == false && sum1 < sum2)
        {
            return -1;
        }
        if(lock2 == false && sum2 < sum1)
        {
            return -1;
        }

        return max(sum1, sum2);
    }
};