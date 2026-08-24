class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int len = nums.size();
        int temp = 0;
        unordered_map<int, int> count;
        vector<int> appear;

        for(int i = 0; i<len ;i++)
        {
            if(count[nums[i]]++ == 0)
            {
                appear.push_back(nums[i]);
            }
        }

        len = appear.size();

        for(int i = 0; i<len; i++)
        {
            for(int j = i+1; j<len; j++)
            {
                if(appear[i]>appear[j])
                {
                    temp = appear[i];
                    appear[i] = appear[j];
                    appear[j] = temp;
                }
            }
        }

        for(int i = 0; i<len; i++)
        {
            count[appear[i]]--;
            for(int j = i; j<len; j++)
            {
                if(count[appear[j]] == 0)
                {
                    if(j == len - 1)
                    {
                        continue;
                    }
                    j++;
                }
                count[appear[j]]--;
                if(count[-(appear[i]+appear[j])] > 0 && -(appear[i]+appear[j]) >= appear[j])
                {
                    ans.push_back({appear[i], appear[j], -(appear[i]+appear[j])});
                }
                count[appear[j]]++;
            }
            count[appear[i]]++;
        }


        return ans;
    }
};