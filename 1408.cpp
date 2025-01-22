class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int len = words.size();
        string temp = "";
        vector<string> ans;
        for(int i = 0; i<len; i++)
        {
            temp = words[i];
            for(int j = 0; j<len; j++)
            {
                if( i != j)
                {
                    if(words[j].contains(temp))
                    {
                        ans.push_back(temp);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};