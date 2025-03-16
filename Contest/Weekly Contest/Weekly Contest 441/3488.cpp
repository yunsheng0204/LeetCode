class Solution {
    public:
        vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
            long long len_nums = nums.size();
            long long len_queries = queries.size();
            long long len_temp;
            long long temp = 0;
            long long temp2 = 0;
            long long min1 = 0;
            long long num1 = 0, num2 = 0;
            long long max1 = 0;
            vector<int> ans;
            unordered_map<int, vector<int>> pos;
            vector<int> t;
    
            for(long long i = 0; i<len_nums; i++)
            {
                pos[nums[i]].push_back(i);
            }
            
    
            for(long long i = 0; i<len_queries; i++)
            {
                temp = nums[queries[i]];
                t = pos[temp];
    
                len_temp = t.size();
    
                // for(long long j = 0; j<len_temp; j++)
                //     {
                //         cout<<t[j]<<" ";
                //     }
                // cout<<endl;
    
                if(len_temp == 1)
                {
                    ans.push_back(-1);
                }
                else
                {
                    long long left = 0, right = len_temp - 1, mid;
                    while(left<=right)
                    {
                        mid = (left + right) / 2;
                        if(t[mid]==queries[i])
                        {
                            break;
                        }
                        else if(t[mid]<queries[i])
                        {
                            left = mid + 1;
                        }
                        else
                        {
                            right = mid - 1;
                        }
                    }
                    // cout<<t[mid]<<" "<<queries[i]<<endl;
                    if(mid == 0)
                    {
                        num1 = len_nums - t[len_temp - 1] + t[0];
                        num2 = t[mid + 1] - t[mid];
                    }
                    else if(mid == len_temp - 1)
                    {
                        num1 = t[mid] - t[mid - 1];
                        num2 = len_nums - t[mid] + t[0];
                    }
                    else
                    {
                        num1 = t[mid] - t[mid - 1];
                        num2 = t[mid + 1] - t[mid];
                    }
                    // cout<<num1<<" "<<num2<<endl;
                    min1 = min(num1, num2);
                    
                    ans.push_back(min1);
                }
            }
            return ans;
        }
    };