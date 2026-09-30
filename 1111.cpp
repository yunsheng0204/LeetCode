class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int len = seq.size();
        int dep1 = 0;
        int dep2 = 0;
        vector<int> ans(len, 0);
        vector<int> t(len, 0);
        int index = 0;
        for(int i = 0; i<len; i++)
        {
            if(seq[i] == '(')
            {
                if(dep1 <= dep2)
                {
                    dep1++;
                    ans[i] = 0;
                    t[index++] = 0;
                }
                else
                {
                    dep2++;
                    ans[i] = 1;
                    t[index++] = 1;
                }
            }
            else
            {
                if(t[--index] == 0)
                {
                    ans[i] = 0;
                    dep1--;
                }
                else
                {
                    ans[i] = 1;
                    dep2--;
                }
            }
        }

        return ans;
    }
};