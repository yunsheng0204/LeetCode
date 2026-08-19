class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        int ans = 0;
        vector<bool> check(2, false);

        unordered_map<int, vector<bool>> s;

        for(int i = 0; i < reservedSeats.size(); i++)
        {
            int row = reservedSeats[i][0] - 1;
            int seat = reservedSeats[i][1] - 1;

            if(s.find(row) == s.end())
            {
                s[row] = vector<bool>(10, false);
            }

            s[row][seat] = true;
        }

        ans = (n - s.size()) * 2;

        for(auto &row : s)
        {
            vector<bool>& seat = row.second;

            check[0] = false;
            check[1] = false;

            if(seat[1] == false &&
               seat[2] == false &&
               seat[3] == false &&
               seat[4] == false)
            {
                ans++;
                check[0] = true;
            }

            if(seat[3] == false &&
               seat[4] == false &&
               seat[5] == false &&
               seat[6] == false &&
               check[0] == false)
            {
                ans++;
                check[1] = true;
            }

            if(seat[5] == false &&
               seat[6] == false &&
               seat[7] == false &&
               seat[8] == false &&
               check[1] == false)
            {
                ans++;
            }
        }

        return ans;
    }
};