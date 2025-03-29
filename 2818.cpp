class Solution {
    public:
        int maximumScore(vector<int>& nums, int k) {
            int len_n = nums.size();
            long long int ans = 1;
            int index = 1;
            bool check = false;
            map<int, int> factor_number;
            vector<int> factor_array(len_n, 0);
            vector<int> left(len_n, 0);
            vector<int> right(len_n, 0);
            vector<long> range(len_n, 0);
            vector<vector<int>> s;
            vector<long> temp(3, 0);
            stack<int> st;
            priority_queue<vector<long>> pq;
            const long long MOD = 1e9 + 7;
    
            for(int i = 0; i<len_n; i++)
            {
                if(factor_number.find(nums[i]) == factor_number.end())
                {
                    factor_number[nums[i]] = count_factor(nums[i]);
                }
                factor_array[i] = factor_number[nums[i]];
            }
    
            for (int i = 0; i < len_n; i++) 
            {
                while (st.size() != 0 && factor_array[st.top()] < factor_array[i]) 
                {
                    st.pop();
                }
                if(st.size() == 0)
                {
                    left[i] = -1;
                }
                else
                {
                    left[i] = st.top();
                }
                st.push(i);
            }
    
            while (st.size() != 0) 
            {
                st.pop();
            }
            
            for (int i = len_n - 1; i >= 0; i--) 
            {
                while (st.size() != 0 && factor_array[st.top()] <= factor_array[i]) 
                {
                    st.pop();
                }
                if(st.size() == 0)
                {
                    right[i] = len_n;
                }
                else
                {
                    right[i] = st.top();
                }
                st.push(i);
            }
    
            // for(int i = 0; i<len_n; i++)
            // {
            //     cout<<left[i]<<" ";
            // }
            // cout<<endl;
            // for(int i = 0; i<len_n; i++)
            // {
            //     cout<<right[i]<<" ";
            // }
            // cout<<endl;
    
            for(int i = 0; i<len_n; i++)
            {
                range[i] = (long)(i-left[i]) * (right[i]-i);
                pq.push({nums[i], range[i]});
            }
    
            while (k > 0) 
            {
                temp = pq.top();
                pq.pop();
                if (temp[1] > k) 
                {
                    ans = (ans * fast_pow(temp[0], k, MOD)) % MOD;
                    k = 0;
                }
                else
                {
                    ans = (ans * fast_pow(temp[0], temp[1], MOD)) % MOD;
                    k -= temp[1];
                    temp[1] = 0;
                }
            }
    
            return (int)ans;
        }
    
        int count_factor(int num)
        {
            // cout<<"找 "<<num<<endl;
            // vector<int> factor;
            int up = sqrt(num);
            int count = 0;
    
            for(int i = 2; i<=up; i++)
            {
                if(num % i == 0)
                {
                    count++;
                    // factor.push_back(i);
                    // cout<<i<<" ";
                    while(num % i == 0)
                    {
                        num = num / i;
                    }
                }
            }
            if(num > 1)
            {
                count++;
                // factor.push_back(num);
                // cout<<num<<" ";
            }
            // cout<<endl;
            return count;
        }
    
        long long fast_pow(long long base, long long exp, long long mod) 
        {
            long long res = 1;
            while (exp > 0) {
                if (exp % 2 == 1) {
                    res = (res * base) % mod;
                }
                base = (base * base) % mod;
                exp /= 2;
            }
            return res;
        }
    };