class Solution {
public:
    bool zuo[1005][1005], you[1005][1005];
    int f[1005][1005];
    
    void calc_palin(string s, bool f[1005][1005]){
        int i, j, mid, n = s.size();
        for (i = 0; i < n; ++i)
            for (j = i; j < n; ++j)
                f[i][j] = false;
        
        for (mid = 0; mid < n; ++mid){
            i = j = mid;
            while (i >= 0 && j < n && s[i] == s[j]){
                f[i][j] = true;
                --i;
                ++j;
            }
            i = mid; j = mid + 1;
            while (i >= 0 && j < n && s[i] == s[j]){
                f[i][j] = true;
                --i;
                ++j;
            }
        }
    }
    
    int longestPalindrome(string s, string t) {
        int m = s.size(), n = t.size(), i, j, k, zd, res = 1;
        calc_palin(s, zuo); 
        calc_palin(t, you);
        for (i = 0; i < m; ++i)
            for (j = i; j < m; ++j)
                if (zuo[i][j])
                    res = max(res, j - i + 1);
        
        for (i = 0; i < n; ++i)
            for (j = i; j < n; ++j)
                if (you[i][j])
                    res = max(res, j - i + 1);
        
        // calc f
        for (i = 0; i < m; ++i)
            for (j = n - 1; j >= 0; --j)
                if (s[i] != t[j]) f[i][j] = 0;
                else{
                    f[i][j] = 2;
                    if (i - 1 >= 0 && j + 1 < n)
                        f[i][j] += f[i - 1][j + 1];
                }
            
        for (i = 0; i < m; ++i){
            zd = 0;
            for (j = 0; j < n; ++j) zd = max(zd, f[i][j]);
            if (zd == 0) continue;
            for (j = m - 1; j > i; --j)
                if (zuo[i+1][j]){
                    zd += j - i;
                    break;
                }
            
            res = max(zd, res);
        }
        
        for (j = 0; j < n; ++j){
            zd = 0;
            for (i = 0; i < m; ++i) zd = max(zd, f[i][j]);
            if (zd == 0) continue;
            for (i = 0; i < j; ++i)
                if (you[i][j - 1]){
                    zd += j - i;
                    break;
                }
            
            res = max(zd, res);
        }
        
        return res;
    }
};