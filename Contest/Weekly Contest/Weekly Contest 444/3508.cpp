class Router {
private:
    int limit;
    deque<vector<int>> q;
    unordered_set<long long> packet_map;
    unordered_map<int, vector<int>> time_map;

    long long getKey(int source, int destination, int timestamp) 
    {
        return ((long long)source << 40) | ((long long)destination << 20) | timestamp;
    }

public:
    Router(int memoryLimit) {
        limit = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        long long key = getKey(source, destination, timestamp);
        if (packet_map.count(key)) return false;

        if (q.size() >= limit) {
            vector<int> old = q.front();
            q.pop_front();
            long long old_key = getKey(old[0], old[1], old[2]);
            packet_map.erase(old_key);

            vector<int>& vec = time_map[old[1]];
            vector<int>::iterator it = lower_bound(vec.begin(), vec.end(), old[2]);
            if (it != vec.end() && *it == old[2]) {
                vec.erase(it);
            }
        }

        q.push_back({source, destination, timestamp});
        packet_map.insert(key);
        time_map[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty()) return {};

        vector<int> temp = q.front();
        q.pop_front();
        long long key = getKey(temp[0], temp[1], temp[2]);
        packet_map.erase(key);

        vector<int>& vec = time_map[temp[1]];
        vector<int>::iterator it = lower_bound(vec.begin(), vec.end(), temp[2]);
        if (it != vec.end() && *it == temp[2])
        {
            vec.erase(it);
        }

        return temp;
    }

    int getCount(int destination, int startTime, int endTime) {
        vector<int>& vec = time_map[destination];
        vector<int>::iterator it1 = lower_bound(vec.begin(), vec.end(), startTime);
        vector<int>::iterator it2 = upper_bound(vec.begin(), vec.end(), endTime);
        return it2 - it1;
    }
};
