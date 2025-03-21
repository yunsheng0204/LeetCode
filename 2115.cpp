class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            map<string, int> food_index;
            map<int, string> food_index_inv;
            int len_r = recipes.size();
            int len_i = ingredients.size();
            int len_temp;
            int len_s = supplies.size();
            int index = 0;
            string temp_r = "";
            vector<string> temp_i;
            string temp_s;
            vector<string> ans; 
            string temp;
    
            for(int i = 0; i<len_s; i++)
            {
                temp_s = supplies[i];
                if(food_index[temp_s] ==  0)
                {
                    food_index[temp_s] = index;
                    food_index_inv[index] = temp_s;
                    // cout<<temp_s<<" 的編號是: "<<index<<endl;
                    index++;
                }
            }
    
            for(int i = 0; i<len_i; i++)
            {
                temp_i = ingredients[i];
                len_temp = temp_i.size();
                for(int j = 0; j<len_temp; j++)
                {
                    if(food_index[temp_i[j]] ==  0)
                    {
                        food_index[temp_i[j]] = index;
                        food_index_inv[index] = temp_i[j];
                        // cout<<temp_i[j]<<" 的編號是: "<<index<<endl;
                        index++;
                    }
                }
            }
    
            for(int i = 0; i<len_r; i++)
            {
                temp_r = recipes[i];
                if(food_index[temp_r] ==  0)
                {
                    food_index[temp_r] = index;
                    food_index_inv[index] = temp_r;
                    // cout<<temp_r<<" 的編號是: "<<index<<endl;
                    index++;
                }
            }
    
            vector<vector<bool>> graph(index, vector<bool> (index, false));
            map<string, int> indegree;
            queue<string> q;
    
            for(int i = 0; i<len_r; i++)
            {
                temp_r = recipes[i];
                len_temp = ingredients[i].size();
                indegree[temp_r] = len_temp;
    
                // cout<<temp_r<<" 要 "<<len_temp<<" 個材料"<<endl;
            }
    
            for(int i = 0; i<len_s; i++)
            {
                temp_s = supplies[i];
                q.push(temp_s);
            }
    
            for(int i = 0; i<len_i; i++)
            {
                temp_r = recipes[i];
                temp_i = ingredients[i];
    
                len_temp = temp_i.size();
                for(int j = 0; j<len_temp; j++)
                {
                    graph[food_index[temp_r]][food_index[temp_i[j]]] = true;
                }
            }
    
            while(q.size()!=0)
            {
                temp = q.front();
                q.pop();
                for(int i = 0; i<index; i++)
                {
                    if(graph[i][food_index[temp]] == true)
                    {
                        graph[i][food_index[temp]] = false;
                        
                        // cout<<"因為 "<<temp<<"，所以 "<<food_index_inv[i]<<"所需材料剩 "<<indegree[food_index_inv[i]] - 1<<endl;
                        if(--indegree[food_index_inv[i]] == 0)
                        {
                            ans.push_back(food_index_inv[i]);
                            q.push(food_index_inv[i]);
                        }
                    }
                }
            }
    
    
            return ans;
        }
    };