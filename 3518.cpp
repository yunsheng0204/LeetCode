class Solution {
public:
    string smallestPalindrome(string s, int k) {
        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;

        string mid = "";
        for (int i = 0; i < 26; ++i) {
            if (count[i] % 2) {
                if (!mid.empty()) return "";
                mid += (char)('a' + i);
            }
            count[i] /= 2;
        }

        int total = accumulate(count.begin(), count.end(), 0);
        vector<double> logFact(total + 1, 0.0);
        for (int i = 1; i <= total; ++i) {
            logFact[i] = logFact[i - 1] + log(i);
        }

        auto logCountPerm = [&](const vector<int>& freq) -> double {
            int sum = 0;
            for (int f : freq) sum += f;
            double res = logFact[sum];
            for (int f : freq) res -= logFact[f];
            return res;
        };

        auto isEnough = [&](const vector<int>& freq, int k) -> bool {
            return logCountPerm(freq) >= log((double)k) - 1e-9;
        };

        if (!isEnough(count, k)) return "";

        string half = "";
        while ((int)half.size() < total) {
            for (int i = 0; i < 26; ++i) {
                if (count[i] == 0) continue;

                count[i]--;
                if (isEnough(count, k)) {
                    half += (char)('a' + i);
                    break;
                } else {
                    k -= (int)(exp(logCountPerm(count)) + 1e-6); 
                    count[i]++;
                }
            }
        }

        string rev = half;
        reverse(rev.begin(), rev.end());
        return half + mid + rev;
    }
};
cleetcode
