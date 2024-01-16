class RandomizedSet {
public:
    unordered_map <int,int> arr;
    vector<int> v;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(arr.find(val)==arr.end()){
            v.push_back(val);
            arr[val] = v.size()-1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(arr.find(val)!=arr.end()){
            int index = arr[val];
            arr[v[v.size()-1]] = index;
            swap(v[index] , v[v.size()-1]);
            v.pop_back();
            arr.erase(arr.find(val));
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

