class Solution {
    public:
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            int n = nums.size();
            int m = queries.size();
            
            int left = 1;
            int right = m;
            int result = -1;
            
            for(int i = 0; i<n; i++)
            {
                if(nums[i] != 0)
                {
                    break;
                }
                else if(i == n-1)
                {
                    return 0;
                }
            }
            
            while (left <= right) 
            {
                int mid = (left + right) / 2;
                
                if ( isPossible(mid, nums, queries, n) ) 
                {
                    result = mid;
                    right = mid - 1;
                } 
                else 
                {
                    left = mid + 1;
                }
            }
            return result;
        }
    
        bool isPossible(int k, vector<int> &nums, vector<vector<int>> &queries, int n)
        {
            vector<int> diff(n + 1, 0);
            vector<int> curr = nums;
    
            for (int i = 0; i < k; i++) 
            {
                diff[ queries[i][0] ] -= queries[i][2];
                diff[ queries[i][1] + 1] += queries[i][2];
            }
    
            int currDiff = 0;
            for (int i = 0; i < n; i++) 
            {
                currDiff += diff[i];
                curr[i] += currDiff;
                if (curr[i] < 0) 
                {
                    curr[i] = 0;
                }
            }
    
    
            for (int i = 0; i < n; i++) 
            {
                if (curr[i] != 0) 
                {
                    return false;
                }
            }
            return true;
        }
    };
    