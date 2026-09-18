class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        vector<int> pre(n + 1, INT_MAX);

        int left = 0;
        int sum = 0;
        int ans = INT_MAX;

        for(int right = 0; right < n; right++)
        {
            sum += arr[right];

            while(sum > target)
            {
                sum -= arr[left];
                left++;
            }

            pre[right + 1] = pre[right];

            if(sum == target)
            {
                int curLen = right - left + 1;

                if(pre[left] != INT_MAX)
                {
                    ans = min(ans, pre[left] + curLen);
                }

                pre[right + 1] = min(pre[right + 1], curLen);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};