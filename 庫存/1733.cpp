class Solution {
public:
    int minimumTeachings(int n,
                         vector<vector<int>>& languages,
                         vector<vector<int>>& friendships) {
        int m = languages.size();                // 使用者數量（1-indexed in problem）
        // 把每位使用者的語言轉成 set，方便查詢
        vector<unordered_set<int>> know(m + 1);
        for (int i = 0; i < m; ++i) {
            for (int L : languages[i]) know[i + 1].insert(L);
        }

        // 1) 找出所有「不通」的朋友邊，收集相關使用者
        unordered_set<int> badUsers;
        auto canTalk = [&](int u, int v) {
            // iterate the smaller set
            const auto &A = (know[u].size() < know[v].size()) ? know[u] : know[v];
            const auto &B = (know[u].size() < know[v].size()) ? know[v] : know[u];
            for (int L : A) if (B.count(L)) return true;
            return false;
        };

        for (auto &e : friendships) {
            int u = e[0], v = e[1];
            if (!canTalk(u, v)) {
                badUsers.insert(u);
                badUsers.insert(v);
            }
        }
        if (badUsers.empty()) return 0; // 全部本來就互通

        // 2) 嘗試選每種語言，計算需要補教的人數
        vector<int> cnt(n + 1, 0); // cnt[L] = 在 badUsers 裡已經會 L 的人數
        for (int u : badUsers) {
            for (int L : know[u]) cnt[L]++;
        }

        int need = INT_MAX;
        int totalBad = (int)badUsers.size();
        for (int L = 1; L <= n; ++L) {
            need = min(need, totalBad - cnt[L]);
        }
        return need;
    }
};