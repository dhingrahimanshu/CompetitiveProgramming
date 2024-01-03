class Solution {

public:
    vector<int> getRow(int rowIndex) {
        vector <int> ans(1 , 1);
        for(int i = 1;i<=rowIndex;i++){
            vector<int> temp(i+1);
            temp[0]=1;
            temp[i]=1;
            for(int j =1;j<i;j++){
                temp[j]= (ans[j]+ans[j-1]);
            }
            ans = temp;
        }


        return ans;
    }
};
