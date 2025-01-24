class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int len = graph.size();
        int len2, j, temp;

        queue<int> Terminal;
        vector<vector<int>> reverse_graph(len, vector<int>(0));
        vector<bool> Terminal_check(len, 0);
        vector<int> count(len, 0);
        vector<int> ans;

        for(int i = 0; i<len; i++)
        {
            len2 = graph[i].size();
            if(len2 == 0)
            {
                Terminal.push(i);
                Terminal_check[i] = 1;
            }
            else
            {
                for(j = 0; j<len2; j++)
                {
                    reverse_graph[ graph[i][j] ].push_back(i);
                }
            }
        }

        for(int i = 0; i<len; i++)
        {
            count[i] = graph[i].size();
        }

        while(Terminal.size()!=0)
        {
            temp = Terminal.front();
            Terminal.pop();
            len2 = reverse_graph[temp].size();
            for(int i = 0; i<len2; i++)
            {
                if( --count[reverse_graph[temp][i]] == 0)
                {
                    Terminal.push(reverse_graph[temp][i]);
                    Terminal_check[reverse_graph[temp][i]] = 1;
                }
            }
        }

        for(int i = 0; i<len; i++)
        {
            if(Terminal_check[i] == 1)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};