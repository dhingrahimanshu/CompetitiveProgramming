class Solution {
public:

    string helper(int n){
        string arr[] = {"Gold Medal" , "Silver Medal" , "Bronze Medal"};
        if(n<=2)return arr[n];
        string uf = to_string(n+1);
        return uf;
    }

    vector<string> findRelativeRanks(vector<int>& score) {
        int n = (int)score.size();
        vector<string> uf(n);
        vector<pair <int,int>> arr;
        for(int i =0;i<n;i++){
            arr.push_back({score[i] , i});
        }
        sort(arr.begin() , arr.end() , greater<pair<int,int>>());
        for(int i =0;i<n;i++){
            uf[arr[i].second] = helper(i);
        }


        return uf;
    }
};
