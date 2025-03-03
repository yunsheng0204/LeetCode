class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            vector<int> less;
            vector<int> equal;
            vector<int> greater;
            vector<int> ans;
    
            int len = nums.size();
    
            for(int i = 0; i<len; i++)
            {
                if(nums[i] < pivot)
                {
                    less.push_back(nums[i]);
                }
                else if(nums[i] > pivot)
                {
                    greater.push_back(nums[i]);
                }
                else
                {
                    equal.push_back(nums[i]);
                }
            }
            copy(less.begin(), less.end(), back_inserter(ans));
            copy(equal.begin(), equal.end(), back_inserter(ans));
            copy(greater.begin(), greater.end(), back_inserter(ans));
    
            return ans;
        }
    };