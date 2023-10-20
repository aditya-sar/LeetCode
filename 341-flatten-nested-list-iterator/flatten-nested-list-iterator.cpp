class NestedIterator {
public:
    vector<NestedInteger> a;
    vector<int> v;
    int pos = 0;

    void flatten(vector<NestedInteger>& currentList) {
        for(int i = 0; i < currentList.size(); i++) {
            if (currentList[i].isInteger()) {
                v.push_back(currentList[i].getInteger());
            } 
            else {
                flatten(currentList[i].getList());
            }
        }
    }
    
    NestedIterator(vector<NestedInteger> &a) {
        this->a = a;
        flatten(a);
    }

    int next() {
        int number = v[pos];
        pos++;
        return number;
    }

    bool hasNext() {
        return pos < v.size();
    }
};