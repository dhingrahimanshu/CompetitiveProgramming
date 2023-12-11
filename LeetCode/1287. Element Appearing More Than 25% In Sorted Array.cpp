class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        map <int,int> temp;
        for(auto & it : arr){
            temp[it]++;
        }
        for(auto &it: temp){
            if(it.second > (arr.size()/4))return it.first;
        }
        return 0;
    }
};
