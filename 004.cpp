class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int leng = nums1.size() + nums2.size();
        int leng1 = nums1.size();
        int leng2 = nums2.size();

        double number1, number2, ans;
        int pos1 = 0, pos2 = 0;

        vector<int> sort;
        
        for(int i = 0; i<leng; i++)
        {
            if(pos1==leng1)
            {
                sort.push_back(nums2[pos2]);
                pos2++;
            }
            else if(pos2==leng2)
            {
                sort.push_back(nums1[pos1]);
                pos1++;
            }
            else if(nums1[pos1]>=nums2[pos2])
            {
                sort.push_back(nums2[pos2]);
                pos2++;
            }
            else
            {
                sort.push_back(nums1[pos1]);
                pos1++;
            }
        }

        if(leng %2 == 1)
        {
            ans = sort[leng/2];
        }
        else
        {
            number1 = sort[(leng/2)-1];
            number2 = sort[leng/2];

            ans = (number1 + number2)/2;
        }
        return ans;
    }
};