class Solution {
    public:
        int minTimeToReach(vector<vector<int>>& moveTime) {
            int row = moveTime.size();
            int col = moveTime[0].size();
    
            vector<vector<int>> dist(row, vector<int>(col, INT_MAX));
            tuple<int, int, int> temp;
    
            priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    
            dist[0][0] = 0;
            pq.emplace(0, 0, 0);
    
            int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
            while (!pq.empty()) 
            {
                temp = pq.top();
                pq.pop();
    
                if (get<1>(temp) == row - 1 && get<2>(temp) == col - 1) 
                {
                    return get<0>(temp);
                }
    
                if (get<0>(temp) > dist[get<1>(temp)][get<2>(temp)]) 
                {
                    continue;
                }
    
                for (int i = 0; i<4; i++) 
                {
                    int next_x = get<1>(temp) + dirs[i][0];
                    int next_y = get<2>(temp) + dirs[i][1];
    
                    if (next_x < 0 || next_y < 0 || next_x >= row || next_y >= col) 
                    {
                        continue;
                    }
    
                    int next_time = max(get<0>(temp) + 1, moveTime[next_x][next_y] + 1);
    
                    if (next_time < dist[next_x][next_y]) 
                    {
                        dist[next_x][next_y] = next_time;
                        pq.emplace(next_time, next_x, next_y);
                    }
                }
            }
            return -1;
        }
    };