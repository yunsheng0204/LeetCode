class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        string front = "", middle = "";
        for (int i = 0; i < 26; i++) {
            char ch = 'a' + i;
            int half = count[i] / 2;
            front.append(half, ch);
            if (count[i] % 2 == 1 && middle.empty()) {
                middle = ch;
            }
        }

        string end = front;
        reverse(end.begin(), end.end());

        return front + middle + end;
    }
};
cleetcode
