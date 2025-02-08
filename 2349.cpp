class NumberContainers {
public:
    map<long long int, set<long long int>> number_to_index;
    map<long long int, long long  int> container;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(container.find(index) != container.end()  && container[index] != number)
        {
            number_to_index[ container[index] ].erase(index);
        }
        number_to_index[number].insert(index);
        container[index] = number;
    }
    
    int find(int number) {
        if( number_to_index.find(number) != number_to_index.end() && !number_to_index[number].empty())
        {
            return *number_to_index[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */