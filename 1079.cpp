class Solution {
    public:
        int numTilePossibilities(string tiles) {
            int len = tiles.size();
            int ans = 0;
            vector<int> q;
    
            int count[26] = {};
    
            for(int i = 0; i<len; i++)
            {
                if( ++count[ tiles[i] - 'A'] == 1)
                {
                    q.push_back( tiles[i] - 'A');
                }
            }
    
            int len2 = q.size();
    
            count_t(q, ans, count, len2);
    
            return ans;
    
        }
    
        void count_t(vector<int> &q, int &ans, int *count, int &len2)
        {
            for(int i = 0; i<len2 ;i++)
            {
                if(count[q[i]] > 0)
                {
                    count[q[i]]--;
                    ans++;
                    count_t(q, ans, count, len2);
                    count[q[i]]++;
                }
            }
        }
    };