class Solution {
public:
    vector<int> minOperations(string boxes) {
        int len = boxes.size();
        int move = 0;
        vector<int> pos;
        vector<int> ans;
        for(int i = 0; i<len; i++)
        {
            if(boxes[i] == '1')
            {
                pos.push_back(i);
            }
        }
        
        int ball_len = pos.size();
        for(int i = 0; i<len; i++)
        {
            for(int j = 0; j<ball_len; j++)
            {
                move = move + abs(i-pos[j]);
            }
            ans.push_back(move);
            move = 0;
        }
        return ans;
    }
};