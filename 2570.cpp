class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            int len1 = nums1.size();
            int len2 = nums2.size();
    
            int i1 = 0;
            int i2 = 0;
    
            vector<vector<int>> ans;
            vector<int> temp(2, 0);
    
            while(i1<len1 || i2<len2)
            {
                if(i1 == len1)
                {
                    temp[0] = nums2[i2][0];
                    temp[1] = nums2[i2][1];
                    ans.push_back(temp);
                    i2++;
                }
                else if(i2 == len2)
                {
                    temp[0] = nums1[i1][0];
                    temp[1] = nums1[i1][1];
                    ans.push_back(temp);
                    i1++;
                }
                else if(nums1[i1][0] == nums2[i2][0])
                {
                    temp[0] = nums1[i1][0];
                    temp[1] = nums1[i1][1] + nums2[i2][1];
                    ans.push_back(temp);
                    i1++;
                    i2++;
                }
                else if(nums1[i1][0] < nums2[i2][0])
                {
                    temp[0] = nums1[i1][0];
                    temp[1] = nums1[i1][1];
                    ans.push_back(temp);
                    i1++;
                }
                else
                {
                    temp[0] = nums2[i2][0];
                    temp[1] = nums2[i2][1];
                    ans.push_back(temp);
                    i2++;
                }
            }
            return ans;
        }
    };