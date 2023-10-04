class MyHashMap {
public:
    vector<int> arr;
    MyHashMap() {
        int const a= 1e6 +1;
        arr.resize(a , -1);
    }
    
    void put(int key, int value) {
        arr[key] = value;
    }
    
    int get(int key) {
        return arr[key];
    }
    
    void remove(int key) {
        arr[key]=-1;
    }
};
