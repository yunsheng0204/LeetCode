class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int len = arr.size();
        int count = 0;

        for(int i = 0; i<len; i++)
        {
            if(arr[i] % 2 == 0)
            {
                count = 0;
            }
            else
            {
                if(++count == 3)
                {
                    return true;
                }
            }
        }

        return false;
    }
};