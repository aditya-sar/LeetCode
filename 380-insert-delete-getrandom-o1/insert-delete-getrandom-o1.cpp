class RandomizedSet {
public:
    unordered_set<int> st;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        bool found = st.find(val) != st.end();
        st.insert(val);
        return !found;    
    }
    
    bool remove(int val) {
        bool found = st.find(val) != st.end();
        st.erase(val);
        return found;
    }
    
    int getRandom() {
        int place = rand() % st.size();
        unordered_set<int>::iterator it = st.begin();
        advance(it, place);
        return *it;
    }
};