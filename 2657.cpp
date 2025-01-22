class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> queue1;
        vector<int> queue2;
        vector<int> ans;

        bool check1 = false;
        bool check2 = false;

        int len_1 = queue1.size();
        int len_2 = queue2.size();

        int len = A.size();

        int count = 0;

        for(int i = 0; i<len; i++)
        {
            len_1 = queue1.size();
            len_2 = queue2.size();

            for(int j = 0; j<len_2; j++)
            {
                if(A[i] == queue2[j])
                {
                    count++;
                    queue2.erase(queue2.begin()+j);
                    check1 = true;
                    break;
                }
            }
            for(int j = 0; j<len_1; j++)
            {
                if(B[i] == queue1[j])
                {
                    count++;
                    queue1.erase(queue1.begin()+j);
                    check2 = true;
                    break;
                }
            }
            if(A[i] == B[i])
            {
                count++;
            }

            if(check1 == false)
            {
                queue1.push_back(A[i]);
            }
            else
            {
                check1 = false;
            }

            if(check2 == false)
            {
                queue2.push_back(B[i]);
            }
            else
            {
                check2 = false;
            }

            ans.push_back(count);
        }

        return ans;
    }
};