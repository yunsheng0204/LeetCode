class Solution {
    public:
        int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
            sort(tasks.begin(), tasks.end());
            sort(workers.begin(), workers.end());
    
            long long low = 0;
            long long high = min(tasks.size(), workers.size());
            long long ans = 0;
            long long mid = 0;
    
            while(low <= high)
            {
                mid = (low + high) / 2;
                if(check(mid, tasks, workers, pills, strength))
                {
                    ans = mid;
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
            return ans;
        }
    
        bool check(int mid, vector<int>& tasks, vector<int>& workers, int pills, int strength)
        {
            multiset<int> ms(workers.end() - mid, workers.end());
            int p = pills;
    
            for (int i = mid - 1; i >= 0; i--) 
            { 
                
                auto it = prev(ms.end());
                if (*it >= tasks[i]) 
                {
                    ms.erase(it);
                } 
                else 
                {
                    if (p == 0) 
                    {
                        return false;
                    }
                    it = ms.lower_bound(tasks[i] - strength);
                    if (it == ms.end()) 
                    {
                        return false;
                    }
                    ms.erase(it);
                    p--;
                }
            }
            return true;
        }
    };