class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int len_p = prerequisites.size();
        int len_q = queries.size();
        bool check = 0;

        vector<int> temp;
        vector<bool> ans;

        vector<vector<bool>> maze(numCourses, vector<bool>(numCourses, 0));

        for(int i = 0; i<len_p; i++)
        {
            temp = prerequisites[i];
            
            maze[temp[0]][temp[1]] = 1;
        }

        for(int c = 0; c<numCourses; c++)
        {
            maze[c][c] = 1;
        }

        for(int c = 0; c<numCourses; c++)
        {
            for(int i = 0; i<numCourses; i++)
            {
                for(int j = 0; j<numCourses; j++)
                {
                    if(maze[i][j] == 1)
                    {
                        for(int k = 0; k<numCourses; k++)
                        {
                            if(maze[j][k] == 1)
                            {
                                maze[i][k] = 1;
                                check = 1;
                            }
                        }
                    }
                }
            }
            if(check = 0)
            {
                break;
            }
            else
            {
                check = 0;
            }
        }

        for(int i = 0; i<len_q; i++)
        {
            temp = queries[i];
            if(maze[temp[0]][temp[1]] == 1)
            {
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }

        return ans;
    }
};