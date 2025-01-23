class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> temp_1;
        vector<int> temp_2;

        temp_1.push_back(1);

        temp_2.push_back(1);
        temp_2.push_back(1);

        if(rowIndex == 0)
        {
            return temp_1;
        }
        else if(rowIndex == 1)
        {
            return temp_2;
        }
        else
        {
            for(int c = 2; c<=rowIndex + 1; c++)
            {
                temp_1 = temp_2;
                temp_2.clear();
                temp_2.push_back(1);
                for(int i = 0; i<(c-2); i++)
                {
                    temp_2.push_back(temp_1[i] + temp_1[i+1]);
                }
                temp_2.push_back(1);
            }
            return temp_2;
        }
    }
};