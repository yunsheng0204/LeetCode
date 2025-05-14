class Solution 
{
public:
    int MOD = 1e9 + 7;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(Matrix &a, Matrix &b) 
    {
        Matrix res(26, vector<long long>(26, 0));

        for (int i = 0; i < 26; i++) 
        {
            for (int k = 0; k < 26; k++) 
            {
                if (a[i][k] == 0) 
                {
                    continue;
                }

                for (int j = 0; j < 26; j++) 
                {
                    res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
                }
            }
        }

        return res;
    }

    Matrix matrix_pow(Matrix &base, int power) 
    {
        Matrix res(26, vector<long long>(26, 0));

        for (int i = 0; i < 26; i++) 
        {
            res[i][i] = 1;
        }

        while (power > 0) 
        {
            if (power % 2 == 1) 
            {
                res = multiply(res, base);
            }

            base = multiply(base, base);
            power /= 2;
        }

        return res;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) 
    {
        vector<long long> count(26, 0);

        for (char c : s) 
        {
            count[c - 'a']++;
        }

        // 構造轉移矩陣
        Matrix T(26, vector<long long>(26, 0));

        for (int i = 0; i < 26; i++) 
        {
            for (int j = 1; j <= nums[i]; j++) 
            {
                T[(i + j) % 26][i] = (T[(i + j) % 26][i] + 1) % MOD;
            }
        }

        // 快速冪算 (T ^ t)
        Matrix T_pow = matrix_pow(T, t);

        // 將轉移矩陣乘上 count 向量
        vector<long long> result(26, 0);

        for (int i = 0; i < 26; i++) 
        {
            for (int j = 0; j < 26; j++) 
            {
                result[i] = (result[i] + T_pow[i][j] * count[j]) % MOD;
            }
        }

        long long ans = 0;

        for (int i = 0; i < 26; i++) 
        {
            ans = (ans + result[i]) % MOD;
        }

        return ans;
    }
};

