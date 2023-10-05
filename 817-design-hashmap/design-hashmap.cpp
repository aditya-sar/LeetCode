class Mapnode {
public:
    int key;
    int val;
    Mapnode* next;

    Mapnode(int k = -1, int v = -1, Mapnode* n = nullptr) : key(k), val(v), next(n) {}
};

class MyHashMap {
private:
    vector<Mapnode*> mp;

public:
    MyHashMap() {
        mp.resize(1000);
        for (int i = 0; i < 1000; ++i) {
            mp[i] = new Mapnode();
        }
    }

    int hash(int key) {
        return key % 1000;
    }

    void put(int key, int value) {
        int hash_key = hash(key);
        Mapnode* curr = mp[hash_key];

        while (curr->next) {
            if (curr->next->key == key) {
                curr->next->val = value;
                return;
            }
            curr = curr->next;
        }

        curr->next = new Mapnode(key, value);
    }

    int get(int key) {
        int hash_key = hash(key);
        Mapnode* curr = mp[hash_key];

        while (curr->next) {
            if (curr->next->key == key) {
                return curr->next->val;
            }
            curr = curr->next;
        }

        return -1;
    }

    void remove(int key) {
        int hash_key = hash(key);
        Mapnode* curr = mp[hash_key];

        while (curr->next) {
            if (curr->next->key == key) {
                Mapnode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
                return;
            }
            curr = curr->next;
        }
    }
};
