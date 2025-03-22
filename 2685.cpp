class Solution {
    public:
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            vector<int> root(n, 0);
            vector<int> rank(n, 1);
            vector<int> node_number(n, 0);
            vector<int> degree(n, 1);
            vector<int> root_queue;
            vector<vector<bool>> graph(n, vector<bool>(n, false));
            int temp = 0;
    
            int len_e = edges.size();
            int ans = 0;
    
            for(int i = 0; i<n; i++)
            {
                root[i] = i;
            }
    
            for(int i = 0; i<len_e; i++)
            {
                graph[edges[i][0]][edges[i][1]] = true;
                graph[edges[i][1]][edges[i][0]] = true;
                degree[edges[i][0]]++;
                degree[edges[i][1]]++;
                union_set(edges[i][0], edges[i][1], root, rank);
            }
    
            for(int i = 0; i<n ;i++)
            {
                temp = find_root(i, root);
                if(node_number[temp]++ == 0)
                {
                    root_queue.push_back(temp);
                }
            }
            bool check = true;
            int len_temp = root_queue.size();
            for(int i = 0; i<len_temp ;i++)
            {
                check = true;
                temp = root_queue[i];
                graph[temp][temp] = true;
                for(int j = 0; j<n; j++)
                {
                    if(graph[temp][j] == true)
                    {
                        if(degree[j] != node_number[temp])
                        {
                            check = false;
                            break;
                        }
                    }
                }
                if(check == true)
                {
                    ans++;
                }
            }
    
            return ans;
        }
    
        int find_root(int x, vector<int> &root)
        {
            if(root[x] != x)
            {
                root[x] = find_root(root[x], root);
            }
            return root[x];
        }
    
        void union_set(int x, int y, vector<int> &root, vector<int> &rank)
        {
            int root_x = find_root(x, root);
            int root_y = find_root(y, root);
    
            if(rank[root_x] == rank[root_y])
            {
                rank[root_x]++;
                root[root_y] = root_x;
            }
            else if(rank[root_x] > rank[root_y])
            {
                root[root_y] = root_x;
            }
            else if(rank[root_x] < rank[root_y])
            {
                root[root_x] = root_y;
            }
        }
    };