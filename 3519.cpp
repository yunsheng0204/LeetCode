class Solution {
public:
    const int MOD = 1e9 + 7;
    int base;
    string bound;
    vector<vector<vector<vector<int>>>> dp;

    int dfs(int pos, int prev, bool tight, bool leading_zero) {
        if (pos == bound.size()) return 1;

        if (dp[pos][prev + 1][tight][leading_zero] != -1)
            return dp[pos][prev + 1][tight][leading_zero];

        int res = 0;
        int max_digit = tight ? (bound[pos] - '0') : base - 1;

        for (int d = 0; d <= max_digit; d++) {
            if (!leading_zero && d < prev) continue;

            res += dfs(
                pos + 1,
                (leading_zero && d == 0) ? -1 : d,
                tight && (d == max_digit),
                leading_zero && (d == 0)
            );
            res %= MOD;
        }

        return dp[pos][prev + 1][tight][leading_zero] = res;
    }

    int countUpTo(string num_str) {
        bound = to_base_b(num_str);
        int len = bound.size();
        dp = vector<vector<vector<vector<int>>>>(
            len, vector<vector<vector<int>>>(
                base + 1, vector<vector<int>>(
                    2, vector<int>(2, -1)
                )
            )
        );
        return dfs(0, -1, 1, 1);
    }

    int countNumbers(string l, string r, int b) {
        base = b;
        return (countUpTo(r) - countUpTo(decrement(l)) + MOD) % MOD;
    }

    string to_base_b(string num_str) {
        vector<int> digits;
        vector<int> num;
        for (char c : num_str) num.push_back(c - '0');

        while (!num.empty()) {
            int carry = 0;
            vector<int> new_num;
            for (int d : num) {
                carry = carry * 10 + d;
                if (!new_num.empty() || carry / base > 0)
                    new_num.push_back(carry / base);
                carry %= base;
            }
            digits.push_back(carry);
            num = new_num;
        }

        reverse(digits.begin(), digits.end());
        string res = "";
        for (int d : digits) res += char(d + '0');
        return res.empty() ? "0" : res;
    }

    string decrement(string s) {
        int n = s.size();
        int i = n - 1;
        while (i >= 0 && s[i] == '0') {
            s[i] = '9';
            i--;
        }
        if (i >= 0) s[i]--;
        if (s[0] == '0') s = s.substr(1);
        return s.empty() ? "0" : s;
    }
};
cleetcode
