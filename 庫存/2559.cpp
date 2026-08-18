class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int len = words.size();
        int count = 0;
        int temp_len;

        vector<int> ans;
        vector<int> q;
        vector<int> check;

        for(int i = 0; i<len ;i++)
        {
            temp_len = words[i].size() - 1;
            if( (words[i][0] == 'a' || words[i][0] == 'e' || words[i][0] == 'i' || words[i][0] == 'o' || words[i][0] == 'u') && (words[i][temp_len] == 'a' || words[i][temp_len] == 'e' || words[i][temp_len] == 'i' || words[i][temp_len] == 'o' || words[i][temp_len] == 'u') )
            {
                q.push_back(++count);
                check.push_back(true);
            }
            else
            {
                q.push_back(count);
                check.push_back(false);
            }
            // cout<<q[i]<<" ";
        }

        len = queries.size();
        for(int i = 0; i<len; i++)
        {
            if(check[queries[i][0]] == 1)
            {
                ans.push_back( q[queries[i][1]] - q[queries[i][0]] + 1 );
            }
            else
            {
                ans.push_back( q[queries[i][1]] - q[queries[i][0]] );
            }
        }

        return ans;
    }
};