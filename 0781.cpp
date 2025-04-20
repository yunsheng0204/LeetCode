class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            int len = answers.size();
            int ans = 0;
    
            vector<int> record;
            map<int, int> count;
    
            for(int i = 0; i<len; i++)
            {
                if(answers[i] == 0)
                {
                    ans++;
                }
                else if(count[answers[i]]++ == 0)
                {
                    record.push_back(answers[i]);
                }
            }
    
            len = record.size();
            for(int i = 0; i<len; i++)
            {
                ans += count[record[i]] / (record[i] + 1) * (record[i] + 1);
                if( count[record[i]] % (record[i] + 1) != 0 )
                {
                    ans += (record[i] + 1);
                }
            }
    
            return ans;
        }
    };