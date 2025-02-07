class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int len = queries.size();
        int count = 0;

        unordered_map < long long int, int > count_color_times;
        unordered_map < int, long long int > mapp2;
        
        vector<int> ans;

        for(int i = 0; i<len; i++)
        {
            if( count_color_times.find(queries[i][1]) == count_color_times.end() && mapp2.find(queries[i][0]) == mapp2.end())
            {
                count_color_times[ queries[i][1] ]++;
                mapp2[ queries[i][0] ] = queries[i][1];
                count++;
            }
            else if(mapp2[ queries[i][0] ] != queries[i][1])
            {
                if(++count_color_times[ queries[i][1] ] == 1)
                {
                    count++;
                }
                if(--count_color_times[ mapp2[queries[i][0]] ] == 0)
                {
                    count--;
                }
                mapp2[ queries[i][0] ] = queries[i][1];
            }
            ans.push_back(count);
        }

        return ans;
    }
};