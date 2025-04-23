class Solution {
    public:
        int countLargestGroup(int n) {
            map<int ,int> group;
            int maxi = 0;
            int ans = 0;
            int temp = 0;
            int temp_i;
    
            for(int i = 1; i<=n; i++)
            {
                temp_i = i;
                temp = 0;
                while(temp_i>0)
                {
                    temp += temp_i % 10;
                    temp_i /= 10;
                }
                // cout<<temp<<" "<<group[temp] + 1<<endl;
                if(++group[temp] > maxi)
                {
                    maxi = group[temp];
                    ans = 1;
                }
                else if(group[temp] == maxi)
                {
                    ans++;
                }
            }
            return ans;
        }
    };