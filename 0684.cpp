class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int len = edges.size();
        vector<int>node_in_what_queue(len + 1, 0);
        vector<vector<int>> queue(len, vector<int>(0,0));
        vector<int> temp;
        int t = 1;
        int len1, len2;
        int m;

        for(int i = 0; i<len; i++)
        {
            temp = edges[i];
            // cout<<temp[0]<<" "<<temp[1]<<endl;
            // cout<<node_in_what_queue[ temp[0] ]<<" "<<node_in_what_queue[ temp[1] ]<<" 變 ";
            if(node_in_what_queue[ temp[0] ] == 0 && node_in_what_queue[ temp[1] ] == 0)
            {
                node_in_what_queue[ temp[0] ] = t;
                node_in_what_queue[ temp[1] ] = t;
                queue[t].push_back(temp[0]);
                queue[t].push_back(temp[1]);
                // cout<<temp[0]<<" 放 "<<t<<endl;
                // cout<<temp[1]<<" 放 "<<t<<endl;
                t++;
            }
            else if(node_in_what_queue[ temp[0] ] == 0)
            {
                node_in_what_queue[ temp[0] ] = node_in_what_queue[ temp[1] ];
                // cout<<temp[0]<<" 放 "<<node_in_what_queue[ temp[1] ]<<endl;
                queue[ node_in_what_queue[ temp[1] ] ].push_back(temp[0]);
            }
            else if(node_in_what_queue[ temp[1] ] == 0)
            {
                node_in_what_queue[ temp[1] ] = node_in_what_queue[ temp[0] ];
                // cout<<temp[1]<<" 放 "<<node_in_what_queue[ temp[0] ]<<endl;
                queue[ node_in_what_queue[ temp[0] ] ].push_back(temp[1]);
            }
            else
            {
                if(node_in_what_queue[ temp[0] ] == node_in_what_queue[ temp[1] ])
                {
                    return temp;
                }
                else
                {
                    if(node_in_what_queue[ temp[0] ] < node_in_what_queue[ temp[1] ])
                    {
                        len2 = queue[ node_in_what_queue[ temp[1] ] ].size();
                        m = node_in_what_queue[ temp[1] ];
                        for(int j = 0; j<len2; j++)
                        {
                            node_in_what_queue[ queue[m][j] ] = node_in_what_queue[ temp[0] ];
                            queue[node_in_what_queue[ temp[0] ]].push_back(queue[m][j]);
                        }
                    }
                    else
                    {
                        len1 = queue[ node_in_what_queue[ temp[0] ] ].size();
                        m = node_in_what_queue[ temp[0] ];
                        for(int j = 0; j<len1; j++)
                        {
                            node_in_what_queue[ queue[m][j] ] = node_in_what_queue[ temp[1] ];
                            queue[node_in_what_queue[ temp[1] ]].push_back(queue[m][j]);
                        }
                    }
                }
            }
            // cout<<node_in_what_queue[ temp[0] ]<<" "<<node_in_what_queue[ temp[1] ]<<endl;
        }
        return temp;
    }
};