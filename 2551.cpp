class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int len = weights.size();
        long long maxi = 0;
        long long mini = 0;

        priority_queue<int> max_heap;
        priority_queue<int, vector<int>, greater<int>> min_heap;

        for(int i = 0; i<len - 1; i++)
        {
            max_heap.push(weights[i] + weights[i+1]);
            min_heap.push(weights[i] + weights[i+1]);
        }

        for(int i = 0; i<k-1; i++)
        {
            maxi += max_heap.top();
            mini += min_heap.top();
            max_heap.pop();
            min_heap.pop();
        }

        return maxi - mini;
    }
};