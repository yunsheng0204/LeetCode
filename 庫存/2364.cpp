class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long int len = nums.size();
        long long int len2;
        vector<long long int> que(len, 0);
        vector<long long int> que2;
        long long int count = 0;
        map<long long int, long long int>mapp;

        for(long long int i = 0; i<len; i++)
        {
            que[i] = nums[i] - i;
            if(++mapp[que[i]] == 1)
            {
                que2.push_back(que[i]);
            }
        }
        len2 = que2.size();
        for(long long int i = 0; i<len2; i++)
        {
            count+= mapp[que2[i]] * (len - mapp[que2[i]]);
            // cout<<que2[i]<<" "<<mapp[que2[i]]<<endl;
        }

        return count / 2;
    }
};