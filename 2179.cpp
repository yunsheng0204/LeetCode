class Solution {
    public:
        long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
            int len = nums1.size();
            vector<int> index_2(len);
            vector<int> mapped(len);
            vector<int> bit(len + 2, 0);
            vector<long long> left(len, 0), right(len, 0);
            long long ans = 0;
    
            for(int i = 0; i < len; i++)
            {
                index_2[nums2[i]] = i;
            }
    
            for(int i = 0; i < len; i++)
            {
                mapped[i] = index_2[nums1[i]];
            }
    
            function<void(int)> update = [&](int i)
            {
                i++;
                while(i < (int)bit.size())
                {
                    bit[i]++;
                    i += (i & -i);
                }
            };
    
            function<int(int)> query = [&](int i)
            {
                i++;
                int res = 0;
                while(i > 0)
                {
                    res += bit[i];
                    i -= (i & -i);
                }
                return res;
            };
    
            for(int i = 0; i < len; i++)
            {
                left[i] = query(mapped[i] - 1);
                update(mapped[i]);
            }
    
            fill(bit.begin(), bit.end(), 0);
    
            for(int i = len - 1; i >= 0; i--)
            {
                right[i] = query(len - 1) - query(mapped[i]);
                update(mapped[i]);
            }
    
            for(int i = 0; i < len; i++)
            {
                ans += left[i] * right[i];
            }
    
            return ans;
        }
    };
    