class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int len = nums.size();
        int len1 = 1, len2 = 1;

        vector<int> arr1, arr2;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for(int i = 2; i<len; i++)
        {
            if(arr1[len1 - 1] > arr2[len2 - 1])
            {
                arr1.push_back(nums[i]);
                len1++;
            }
            else
            {
                arr2.push_back(nums[i]);
                len2++;
            }
        }
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};