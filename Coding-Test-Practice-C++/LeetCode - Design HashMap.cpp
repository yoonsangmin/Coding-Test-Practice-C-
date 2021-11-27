#include <iostream>
#include <vector>
using namespace std;

class MyHashMap {
public:
    int size;
    vector<int> key;
    vector<int> value;

    MyHashMap() {
        size = 10000;
        key.assign(size, -1);
        value.assign(size, -1);
    }

    int hashFunction(int key)
    {
        return key % 10000;
    }

    void put(int key, int value) {
        int initial_key = hashFunction(key);
        int cur_key = initial_key;
        int additional_key = 0;

        while (true)
        {
            if (this->key[cur_key] == -1 || this->key[cur_key] == -2) // 넣을 곳에 자리가 있으면
            {
                this->key[cur_key] = key;
                this->value[cur_key] = value;

                return;
            }
            if (this->key[cur_key] == key) // 이미 key가 존재하면
            {
                this->value[cur_key] = value;

                return;
            }
            additional_key++;
            cur_key = (initial_key + additional_key) % size;
            if (cur_key == initial_key)
                return;
        }
    }

    int get(int key) {
        int initial_key = hashFunction(key);
        int cur_key = initial_key;
        int additional_key = 0;

        while (this->key[cur_key] != -1)
        {
            if (this->key[cur_key] == key)
            {
                return this->value[cur_key];
            }
            additional_key++;
            cur_key = (initial_key + additional_key) % size;
            if (cur_key == initial_key)
                return -1;
        }

        return -1;
    }

    void remove(int key) {
        int initial_key = hashFunction(key);
        int cur_key = initial_key;
        int additional_key = 0;

        while (this->key[cur_key] != -1)
        {
            if (this->key[cur_key] == key)
            {
                this->key[cur_key] = -2;
                this->value[cur_key] = -1;
            }
            additional_key++;
            cur_key = (initial_key + additional_key) % size;
            if (cur_key == initial_key)
                return;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */