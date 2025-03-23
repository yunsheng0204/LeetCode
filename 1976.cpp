class Solution {
    public:
        int countPaths(int n, vector<vector<int>>& roads) {
            vector<vector<int>> matrix(n, vector<int> (n, 0));
            vector<vector<int>> neighbor(n, vector<int> (0, 0));
            vector<long long> numerOfPath(n, 0);
            vector<long long> distance(n, LLONG_MAX);
            vector<bool> check(n, false);
            // vector<int> q;
            priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> q;
    
            int temp = 0;
            int temp_len = 0;
            int min_index = 0;
            int min_dis = 0;
    
            int len_r = roads.size();
    
            numerOfPath[0] = 1;
    
            for(int i = 0; i<len_r; i++)
            {
                matrix[roads[i][0]][roads[i][1]] = roads[i][2];
                matrix[roads[i][1]][roads[i][0]] = roads[i][2];
                neighbor[roads[i][0]].push_back(roads[i][1]);
                neighbor[roads[i][1]].push_back(roads[i][0]);
            }
    
            // q.push_back(0);
            q.push({0, 0});
            distance[0] = 0;
            temp_len = neighbor[0].size();
    
            // for(int i = 0; i<temp_len; i++)
            // {
            //     // cout<<neighbor[0][i]<<" "<<matrix[0][neighbor[0][i]]<<endl;
            // }
            
            while(q.size()!=0)
            {
                // temp_len = q.size();
                // min_index = 0;
                // min_dis = distance[q[0]];
                // for(int i = 1; i<temp_len; i++)
                // {
                //     if(min_dis > distance[q[i]])
                //     {
                //         min_index = i;
                //         min_dis = distance[q[i]];
                //     }
                // }
    
                // temp = q[min_index];
                // q.erase(q.begin() + min_index);
    
                min_dis = q.top().first;
                temp = q.top().second;
                q.pop();
    
                if(check[temp] == true)
                {
                    continue;
                }
                check[temp] = true;
                // cout<<"取出 "<<temp<<" 他的距離現在是 "<<min_dis<<endl;
                // cout<<"鄰居: "<<endl;
    
                temp_len  = neighbor[temp].size();
                for(int i = 0; i<temp_len; i++)
                {
                    if(check[neighbor[temp][i]] == false)
                    {
                        // cout<<neighbor[temp][i]<<" 目前距離: "<<distance[neighbor[temp][i]];
                        if(distance[neighbor[temp][i]] > distance[temp] + matrix[temp][neighbor[temp][i]])
                        {
                            distance[neighbor[temp][i]] = distance[temp] + matrix[temp][neighbor[temp][i]];
                            // cout<<" 更新距離為: "<<distance[neighbor[temp][i]];
                            numerOfPath[neighbor[temp][i]] = numerOfPath[temp];
                            numerOfPath[neighbor[temp][i]] %= int(pow(10, 9) + 7);
                            // cout<<" 路徑數: "<<numerOfPath[neighbor[temp][i]];
                            q.push({distance[neighbor[temp][i]], neighbor[temp][i]});
                        }
                        else if(distance[neighbor[temp][i]] == distance[temp] + matrix[temp][neighbor[temp][i]])
                        {
                            numerOfPath[neighbor[temp][i]] += numerOfPath[temp];
                            numerOfPath[neighbor[temp][i]] %= int(pow(10, 9) + 7);
                            // cout<<" 路徑數: "<<numerOfPath[neighbor[temp][i]];
                            q.push({distance[neighbor[temp][i]], neighbor[temp][i]});
                        }
                        // cout<<endl;
                    }
                }
                // cout<<endl;
            }
            return numerOfPath[n-1];
        }
    };