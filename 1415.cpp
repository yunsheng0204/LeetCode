class Solution {
    public:
        vector<string> ans;
        int count_total = 0;
    
        string getHappyString(int n, int k) {
            int count_total = 0;
    
            getHappyStringRecursive('a', 1, "a", n, k);
            getHappyStringRecursive('b', 1, "b", n, k);
            getHappyStringRecursive('c', 1, "c", n, k);
    
            int len = ans.size();
            if(len<k)
            {
                return "";
            }
            else
            {
                return ans[k-1];
            }
            return "";
        }
    
        void getHappyStringRecursive(char now, int count_lit, string temp, int n, int k) {
            if(count_lit == n)
            {
                ans.push_back(temp);
                return;
            } 
            else
            {
                switch(now)
                {
                    case 'a':
                        getHappyStringRecursive('b', count_lit+1, temp + "b", n, k);
                        getHappyStringRecursive('c', count_lit+1, temp + "c", n, k);
                        break;
                    case 'b':
                        getHappyStringRecursive('a', count_lit+1, temp + "a", n, k);
                        getHappyStringRecursive('c', count_lit+1, temp + "c", n, k);
                        break;
                    case 'c':
                        getHappyStringRecursive('a', count_lit+1, temp + "a", n, k);
                        getHappyStringRecursive('b', count_lit+1, temp + "b", n, k);
                        break;
                }
            }
        }
    };