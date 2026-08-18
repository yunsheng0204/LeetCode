class Solution {
    public int[] runningSum(int[] nums) {
        int len = nums.length;
        int sum = 0;
        int ans[] = new int [len];
        for(int i = 0; i<len; i++)
        {
            sum += nums[i];
            ans[i] = sum;
        }
        return ans;
    }
}