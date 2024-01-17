class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map <int,int> hash;
        for(auto & it : arr){
            hash[it]++;
        }
        set<int> a;

        for(auto & it : hash){
            if(a.find(it.second)!=a.end())return false;
            a.insert(it.second);
        }

        return true;
    }
};
