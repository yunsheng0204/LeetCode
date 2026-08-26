class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        vector<int> index;
        int len = s.size();
        int count = 0;
        int mini = INT_MAX;
        int mini_head = 0, mini_end = k-1;

        for(int i = 0; i<len; i++)
        {
            if(s[i] == '1')
            {
                index.push_back(i);
            }
        }

        len = index.size();
        if(k>len)
        {
            return ans;
        }
        for(int head = 0, end = k-1; end<len; head++, end++)
        {
            
            if(index[end] - index[head] < mini)
            {
                mini_head = head;
                mini_end = end;
                mini = index[end] - index[head];
                
            }
            else if(index[end] - index[head] == mini)
            {
                for(int i = 0; i<k; i++)
                {
                    if(index[head + i] - index[head] > index[mini_head + i] - index[mini_head])
                    {
                        mini_head = head;
                        mini_end = end;
                        break;
                    }
                    else if(index[head + i] - index[head] < index[mini_head + i] - index[mini_head])
                    {
                        break;
                    }
                }
            }
        }
        ans = s.substr(index[mini_head], index[mini_end] - index[mini_head] + 1);
        return ans;
    }
};