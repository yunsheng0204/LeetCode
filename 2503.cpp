class Solution {
    public:
        vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
            int len_row = grid.size();
            int len_col = grid[0].size();
            int len_q = queries.size();
            long temp_q = 0;
            tuple<long, int, int> temp_g;
            int count = 0;
            int index = 0;
            int temp_row = 0;
            int temp_col = 0;
            long temp_value = 0;
            vector<vector<bool>> visit (len_row, vector<bool>(len_col, false));
            vector<long> queries_sort(queries.begin(), queries.end());
            vector<int> ans;
            map <long, int> mini;
            priority_queue<tuple<long, int, int> , vector<tuple<long, int, int>>, greater<tuple<long, int, int>>> minHeap;
    
            sort(queries_sort.begin(), queries_sort.end());
    
            minHeap.push({grid[0][0], 0, 0});
    
            while(index < len_q)
            {
                temp_q = queries_sort[index];
                if(minHeap.size()!=0)
                {
                    temp_g = minHeap.top();
                    
                    temp_value =  get<0>(temp_g);
                    temp_row =  get<1>(temp_g);
                    temp_col =  get<2>(temp_g);
    
    
                    if(visit[temp_row][temp_col] == true)
                    {
                        minHeap.pop();
                        continue;
                    }
    
                    // cout<<"檢查 "<<temp_q<<endl;
    
                    if(temp_value >= temp_q)
                    {
                        // cout<<"因 "<<temp_value<<" >= "<<temp_q<<"，所以 "<<temp_q<<" 有 "<<count<<" 個"<<endl;
                        mini[temp_q] = count;
                        index++;
                    }
                    else
                    {
                        // cout<<" 「"<<temp_value<<"」"<<temp_row<<" "<<temp_col<<" 過"<<endl;
                        count++;
                        minHeap.pop();
                        visit[temp_row][temp_col] = true;
                        put(temp_row, temp_col, len_row, len_col, grid, visit, minHeap);
                    }
                }
                else
                {
                    mini[temp_q] = count;
                    index++;
                }
            }
            int i1 = 0;
            for(int i = 0; i<len_q; i++)
            {
                temp_q = queries[i];
                ans.push_back(mini[temp_q]);
                // if(mini[temp_q] == 0)
                // {
                //     i1++;
                //     cout<<i1<<" "<<temp_q<<endl;
                // }
            }
            return ans;
        }
        void put(int row, int col, int len_row, int len_col, vector<vector<int>>& grid, vector<vector<bool>>& visit, priority_queue<tuple<long, int, int> , vector<tuple<long, int, int>>, greater<tuple<long, int, int>>> &minHeap)
        {
            if(row > 0 && row< len_row - 1 && col > 0 && col < len_col - 1)
            {
                if(visit[row - 1][col] == false)                        //上
                {
                    minHeap.push({grid[row - 1][col], row - 1, col});
                }
                if(visit[row + 1][col] == false)                        //下
                {
                    minHeap.push({grid[row + 1][col], row + 1, col});
                }
                if(visit[row][col - 1] == false)                        //左
                {
                    minHeap.push({grid[row][col - 1], row, col - 1});
                }
                if(visit[row][col + 1] == false)                        //右
                {
                    minHeap.push({grid[row][col + 1], row, col + 1});
                }   
            }
            else
            {
                if(row == 0 && col == 0)
                {
                    if(visit[row + 1][col] == false)                        //下
                    {
                        minHeap.push({grid[row + 1][col], row + 1, col});
                    }
                    if(visit[row][col + 1] == false)                        //右
                    {
                        minHeap.push({grid[row][col + 1], row, col + 1});
                    } 
                }
                else if(row == 0 && col == len_col - 1)
                {
                    if(visit[row + 1][col] == false)                        //下
                    {
                        minHeap.push({grid[row + 1][col], row + 1, col});
                    }
                    if(visit[row][col - 1] == false)                        //左
                    {
                        minHeap.push({grid[row][col - 1], row, col - 1});
                    }
                }
                else if(row == len_row - 1 && col == 0)
                {
                    if(visit[row - 1][col] == false)                        //上
                    {
                        minHeap.push({grid[row - 1][col], row - 1, col});
                    }
                    if(visit[row][col + 1] == false)                        //右
                    {
                        minHeap.push({grid[row][col + 1], row, col + 1});
                    } 
                }
                else if(row == len_row - 1 && col == len_col - 1)
                {
                    if(visit[row - 1][col] == false)                        //上
                    {
                        minHeap.push({grid[row - 1][col], row - 1, col});
                    }
                    if(visit[row][col - 1] == false)                        //左
                    {
                        minHeap.push({grid[row][col - 1], row, col - 1});
                    }
                }
                else
                {
                    if(row == 0)
                    {
                        if(visit[row + 1][col] == false)                        //下
                        {
                            minHeap.push({grid[row + 1][col], row + 1, col});
                        }
                        if(visit[row][col - 1] == false)                        //左
                        {
                            minHeap.push({grid[row][col - 1], row, col - 1});
                        }
                        if(visit[row][col + 1] == false)                        //右
                        {
                            minHeap.push({grid[row][col + 1], row, col + 1});
                        } 
                    }
                    else if(row == len_row - 1)
                    {
                        if(visit[row - 1][col] == false)                        //上
                        {
                            minHeap.push({grid[row - 1][col], row - 1, col});
                        }
                        if(visit[row][col - 1] == false)                        //左
                        {
                            minHeap.push({grid[row][col - 1], row, col - 1});
                        }
                        if(visit[row][col + 1] == false)                        //右
                        {
                            minHeap.push({grid[row][col + 1], row, col + 1});
                        } 
                    }
                    else if(col == 0)
                    {
                        if(visit[row - 1][col] == false)                        //上
                        {
                            minHeap.push({grid[row - 1][col], row - 1, col});
                        }
                        if(visit[row + 1][col] == false)                        //下
                        {
                            minHeap.push({grid[row + 1][col], row + 1, col});
                        }
                        if(visit[row][col + 1] == false)                        //右
                        {
                            minHeap.push({grid[row][col + 1], row, col + 1});
                        }
                    }
                    else if(col == len_col - 1)
                    {
                        if(visit[row - 1][col] == false)                        //上
                        {
                            minHeap.push({grid[row - 1][col], row - 1, col});
                        }
                        if(visit[row + 1][col] == false)                        //下
                        {
                            minHeap.push({grid[row + 1][col], row + 1, col});
                        }
                        if(visit[row][col - 1] == false)                        //左
                        {
                            minHeap.push({grid[row][col - 1], row, col - 1});
                        }
                    }
                }
            }
        }
    };