class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            int len = nums.size();
            map<int, int> number_count;
            vector<int> number_appear;
    
            for(int i = 0; i<len; i++)
            {
                if(++number_count[nums[i]] == 1)
                {
                    number_appear.push_back(nums[i]);
                }
            } 
            int len_appear = number_appear.size();
            for(int i =0; i<len_appear; i++)
            {
                if(number_count[number_appear[i]] % 2 != 0)
                {
                    return false;
                }
            }
            return true;
        }
    };