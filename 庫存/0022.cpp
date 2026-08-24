class Solution {
public:
    void p(int &n, int up, int down, vector<string> &ans, string temp)
    {
        if(up == n && down == n)
        {
            ans.push_back(temp);
        }
        else
        {
            if(up == down)
            {
                p(n, up+1, down, ans, temp + "(");
            }
            else if(up > down)
            {
                if(up == n)
                {
                    p(n, up, down+1, ans, temp + ")");
                }
                else
                {
                    p(n, up+1, down, ans, temp + "(");
                    p(n, up, down+1, ans, temp + ")");
                }
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        p(n, 0, 0, ans, "");

        return ans;
    }
};