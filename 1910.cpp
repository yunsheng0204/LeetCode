class Solution {
    public:
        string removeOccurrences(string s, string part) {
            int len_s = s.size();
            int len_part = part.size();
    
            int found_index;
            while( s.find(part) != -1)
            {
                found_index = s.find(part);
                s.erase(found_index, len_part);
            }
            return s;
        }
    };