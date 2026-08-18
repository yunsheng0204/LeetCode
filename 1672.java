class Solution {
    public int maximumWealth(int[][] accounts) {
        int len = accounts.length;
        int len2;
        int temp;
        int ans = 0;

        for(int i = 0; i<len; i++)
        {
            len2 = accounts[i].length;
            temp = 0;
            for(int j = 0; j<len2; j++)
            {
                temp += accounts[i][j];
            }
            ans = Math.max(temp, ans);
        }
        return ans;
    }
}