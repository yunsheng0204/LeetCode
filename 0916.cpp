class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int count_[26] = {0};
        int count_temp[26] = {0};

        int len_1 = words1.size();
        int len_2 = words2.size();
        int len_3 = 0;

        int count_1 = 0;
        char temp;

        vector<string> ans;

        for(int i = 0; i<len_2; i++)
        {
            len_3 = words2[i].size();
            for(int j = 0; j<26; j++)
            {
                count_temp[j] = 0;
            }
            for(int j = 0; j<len_3; j++)
            {
                count_temp[ words2[i][j] - 'a' ]++;
            }
            for(int j = 0; j<26; j++)
            {
                if(count_temp[j] > count_[j])
                {
                    count_[j] = count_temp[j];
                }
            }
        }
        for(int j = 0; j<26; j++)
        {
            temp = j + 'a';
            cout<<temp<<" "<<count_[j]<<endl;
        }

        for(int i = 0; i<len_1; i++)
        {
            ans.push_back(words1[i]);
            for(int j = 0; j<26; j++)
            {
                if(count_[j] == 0)
                {
                    continue;
                }
                temp = 'a' + j;
                count_1 = count(words1[i].begin(), words1[i].end(), temp);
                if( count_1 < count_[j] )
                {
                    ans.pop_back();
                    break;
                }
            }
        }
        return ans;
    }
};