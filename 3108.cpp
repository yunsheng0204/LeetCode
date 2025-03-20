class Solution {
    public:
        vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
            int len_e = edges.size();
            int len_q = query.size();
            vector<int> root(n, 0);
            vector<int> root_min(n, -1);
            vector<int> rank(n, 1);
            vector<int> ans;
            int temp1, temp2;
    
            for(int i = 0; i<n; i++)
            {
                root[i] = i;
            }
    
            for(int i = 0; i<len_e; i++)
            {
                union_sets(edges[i][0], edges[i][1], edges[i][2], root, root_min, rank);
            }
    
            for(int i = 0; i<len_q; i++)
            {
                temp1 = find_root(query[i][0], root, root_min);
                temp2 = find_root(query[i][1], root, root_min);
                if(temp1 == temp2)
                {
                    ans.push_back(root_min[query[i][0]]);
                }
                else
                {
                    ans.push_back(-1);
                }
            }
    
            return ans;
        }
    
        void union_sets(int x, int y, int val, vector<int> &root, vector<int> &root_min, vector<int> &rank)
        {
            int root_X = find_root(x, root, root_min);
            int root_Y = find_root(y, root, root_min);
    
            if(root_X != root_Y)
            {
                if(rank[root_X] == rank[root_Y])
                {
                    if(root_min[root_X] == -1)
                    {
                        root_min[root_X] = val;
                    }
                    else
                    {
                        root_min[root_X] = min(root_min[root_X], (root_min[root_X] & root_min[root_Y]));
                        root_min[root_X] = min(root_min[root_X], (root_min[root_X] & val));
                    }
                    root[root_Y] = root_X;
                    rank[root_X]++;
                }
                else if(rank[root_X] > rank[root_Y])
                {
                    if(root_min[root_Y] == -1)
                    {
                        root_min[root_Y] = val;
                        root_min[root_X] = min(root_min[root_X], (root_min[root_X] & root_min[root_Y]));
                    }
                    else
                    {
                        root_min[root_X] = min(root_min[root_X], (root_min[root_X] & root_min[root_Y]));
                        root_min[root_X] = min(root_min[root_X], (root_min[root_X] & val));
                    }
                    root[root_Y] = root_X;
                }
                else if(rank[root_X] < rank[root_Y])
                {
                    if(root_min[root_X] == -1)
                    {
                        root_min[root_X] = val;
                        root_min[root_Y] = min(root_min[root_Y], (root_min[root_Y] & root_min[root_X]));
                    }
                    else
                    {
                        root_min[root_Y] = min(root_min[root_Y], (root_min[root_Y] & root_min[root_X]));
                        root_min[root_Y] = min(root_min[root_Y], (root_min[root_Y] & val));
                    }
                    root[root_X] = root_Y;
                }
            }
            else
            {
                if(root_min[root_X] != -1)
                {
                    root_min[root_X] = min(root_min[root_X], (root_min[root_X] & val));
                }
            }
        }
    
        int find_root(int x, vector<int> &root, vector<int> &root_min)
        {
            if(root[x] != x)
            {
                root[x] = find_root(root[x], root, root_min);
                root_min[x] = root_min[root[x]];
            }
            return root[x];
        }
    
        
    };