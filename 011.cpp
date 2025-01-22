class Solution {
public:
    int maxArea(vector<int>& height) {
        int leng = height.size();
        int max = 0, cap = 0;
        int pos = 0;
        for(int i = 0; i<leng; i++)
        {
            if(height[i] * (leng - i - 1) < max)
            {
                continue;
            }
            //pos = max / height[i] + i;
            for(int j = i+1; j<leng; j++)
            {
                cap = min(height[i], height[j]) * (j - i);
                if(cap>max)
                {
                    max = cap;
                }
            }
        }
        return max;
    }
};