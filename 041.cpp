class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
        {
            return 0;
        }
        int *a;
        a = new int [len+1];

        for(int i = 0; i<=len ; i++)
        {
            a[i] = 0;
        }
        
        for(int i = 0; i<len ; i++)
        {
            if(nums[i]<=len && nums[i]>0)
            {
                // cout<<nums[i]<<" ";
                a[nums[i]]++;
            }
        }
        int i;
        for(i = 1; i<=len ; i++)
        {
            if( a[i]==0 )
            {
                return i;
            }
        }
        return i;
    }
};