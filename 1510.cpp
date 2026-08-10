class Solution {
public:
    vector<bool> queue = vector<bool>(100001, false);
    bool winnerSquareGame(int n) {

        for(int c = 0; c<=n; c++)
        {
            if(c == 0)
            {
                queue[0] = false;
            }
            else
            {
                int q = sqrt(c);
                for(int i = 1; i<=q; i++)
                {
                    if(  queue[c-i*i] == false  )
                    {
                        queue[c] = true;
                    }
                }
            }

        }
        
        return queue[n];
    }
};