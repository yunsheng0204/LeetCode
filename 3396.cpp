class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            int len = nums.size();
            map<int,int> count;
            int index = -1;
    
            for(int i = len - 1; i>=0; i--)
            {
                if(++count[nums[i]] > 1)
                {
                    index = i;
                    break;
                }
            }
    
            if(index == -1)
            {
                return 0;
            }
            return index / 3 + 1;
        }
    };