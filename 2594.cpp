class Solution {
    public:
        long long repairCars(vector<int>& ranks, int cars) {
            long long len = ranks.size();
            long long ans = 0;
            int count = 0;
            bool check = false;
            sort(ranks.begin(), ranks.end());
    
            long long left = 0, right = (long long)cars * cars * ranks[0], mid;
    
            while(left<=right)
            {
                count = 0;
                check = false;
                mid = (left + right) / 2;
                for(long long i = 0; i<len; i++)
                {
                    count += sqrt(mid / ranks[i]);
                    // cout<<count<<" "<<mid<<endl;
                    if(count >= cars)
                    {
                        check = true;
                        break;
                    }
                }
                if(check == true)
                {
                    // cout<<left<<" "<<mid<<" "<<right<<endl;
                    ans = mid;
                    right = mid - 1;
                }
                else
                {
                    // cout<<left<<" "<<mid<<" "<<right<<endl;
                    left = mid + 1;
                }
            }
    
            return ans;
        }
    };