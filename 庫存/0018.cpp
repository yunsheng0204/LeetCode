class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        
        int len = nums.size();
        unordered_map<long long, int> count;
        vector<int> appear;

        for (int i = 0; i < len; i++)
        {
            if (count[nums[i]]++ == 0)
            {
                appear.push_back(nums[i]);
            }
        }

        len = appear.size();

        for (int i = 0; i < len; i++)
        {
            for (int j = i + 1; j < len; j++)
            {
                if (appear[i] > appear[j])
                {
                    swap(appear[i], appear[j]);
                }
            }
        }

        for (int i = 0; i < len; i++)
        {
            count[appear[i]]--;

            for (int j = i; j < len; j++)
            {
                if (count[appear[j]] == 0)
                {
                    if (j == len - 1)
                    {
                        continue;
                    }
                    j++;
                }

                count[appear[j]]--;

                for (int k = j; k < len; k++)
                {
                    if (count[appear[k]] == 0)
                    {
                        if (k == len - 1)
                        {
                            continue;
                        }
                        k++;
                    }

                    count[appear[k]]--;


                    long long sum = 1LL * target - appear[i]  - appear[j] - appear[k];

                    if (count[sum] > 0 && sum >= appear[k])
                    {
                        ans.push_back({  appear[i],  appear[j], appear[k],  (int)sum  });
                    }

                    count[appear[k]]++;
                }

                count[appear[j]]++;
            }

            count[appear[i]]++;
        }

        return ans;
    }
};