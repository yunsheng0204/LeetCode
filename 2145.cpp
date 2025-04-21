class Solution {
    public:
        int numberOfArrays(vector<int>& differences, int lower, int upper) {
            long long prefix = 0;
            long long min_ps = 0, max_ps = 0;
    
            for (int d : differences) 
            {
                prefix += d;
                min_ps = min(min_ps, prefix);
                max_ps = max(max_ps, prefix);
            }
    
            long long range = max_ps - min_ps;
            long long total_range = upper - lower;
    
            if (range > total_range) return 0;
    
            return total_range - range + 1;
        }
    };