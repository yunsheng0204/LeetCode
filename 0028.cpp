class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.contains(needle) == false)
        {
            return -1;
        }
        else
        {
            int pos = haystack.find(needle);
            return pos;
        }
    }
};