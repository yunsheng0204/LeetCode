class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ans_temp;
        vector<int> temp;
        int len = nums.size();
        int times = pow(2,len) - 1;
        for(int i = 0; i<=times; i++)
        {
            temp = count(i);
            for(int j = 0; j<temp.size(); j++)
            {
                ans_temp.push_back(nums[temp[j]]);
            }
            ans.push_back(ans_temp);
            ans_temp.clear();
        }
        return ans;
    }

    vector<int> count(int i) {
        vector<int> ans;
        int c = 0;

        while(i>0)
        {
            if(i % 2 == 1)
            {
                ans.push_back(c);
            }
            i = i / 2;
            c++;
        }
        cout<<endl;

        return ans;
    }
};