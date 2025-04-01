class Solution {
    public:
        long long mostPoints(vector<vector<int>>& questions) 
        {
            int len = questions.size();
            vector<long long> record(len, -1);
    
            return count_next(questions, 0, len, record);
        }
    
        long long count_next(vector<vector<int>>& questions, int index, int len, vector<long long> &record)
        {
            if(record[index] == -1)
            {
                long long chose1, chose2;
                if(index + questions[index][1] + 1 >= len)
                {
                    chose1 = questions[index][0];
                }
                else
                {
                    chose1 = questions[index][0] + count_next(questions, index + questions[index][1] + 1, len, record);
                }
    
                if(index + 1 >= len)
                {
                    chose2 = 0;
                }
                else
                {
                    chose2 = count_next(questions, index + 1, len, record);
                }
                record[index] = max(chose1, chose2);
            }
            return record[index];
        }
    };